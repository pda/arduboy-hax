#include <errno.h>
#include <libgen.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <sys/wait.h>
#include <unistd.h>

void read_and_exec(int fd, char *watch_filename, char *argv[]);
void exec_command(char *argv[]);

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <file> <command> [args ...]\n", argv[0]);
    fprintf(stderr, "Runs <command> every time <file> is created\n");
    exit(1);
  }
  char *watch_file_path = argv[1];
  char *base = strrchr(watch_file_path, '/');
  char *watch_filename = (base == NULL) ? watch_file_path : base + 1;
  char *watch_file_path_for_dir = strdup(watch_file_path);
  if (watch_file_path_for_dir == NULL) {
    perror("strdup(watch_file_path)");
    exit(1);
  }
  char *watch_dir = dirname(watch_file_path_for_dir);
  char **cmd_argv = argv + 2;

  int fd = inotify_init();
  if (fd == -1) {
    perror("inotify_init");
    exit(1);
  }
  int wd = inotify_add_watch(fd, watch_dir, IN_CREATE);
  if (wd == -1) {
    perror("inotify_add_watch");
    exit(1);
  }
  watch_dir = NULL;
  free(watch_file_path_for_dir);

  while (1) {
    read_and_exec(fd, watch_filename, cmd_argv);
  }

  exit(0);
}

void read_and_exec(int fd, char *watch_filename, char *cmd_argv[]) {
  size_t ev_size = sizeof(struct inotify_event) + NAME_MAX + 1;
  struct inotify_event *ev = malloc(ev_size);
  ssize_t bytes = read(fd, (void *)ev, ev_size);
  if (bytes == -1) {
    perror("read from inotify");
    exit(1);
  } else if (bytes == 0) {
    fputs("read from inotify: 0 bytes\n", stderr);
    exit(1);
  }
  if (strcmp(ev->name, watch_filename) == 0) {
    exec_command(cmd_argv);
  }
}

void exec_command(char *cmd_argv[]) {
  fputs("> ", stderr);
  for (int i = 0; cmd_argv[i] != NULL; i++) {
    fputs(cmd_argv[i], stdout);
    fputc(cmd_argv[i+1] == NULL ? '\n' : ' ', stdout);
  }
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    int err = execvp(cmd_argv[0], cmd_argv);
    if (err == -1) {
      perror("execvp");
      exit(1);
    }
  } else {
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
      printf("command exited with status %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      fprintf(stderr, "command %s\n", strsignal(WTERMSIG(status)));
#ifdef WCOREDUMP
      if (WCOREDUMP(status)) {
        fprintf(stderr, "core dumped\n");
      }
#endif
    }
  }
}
