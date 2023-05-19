CC = clang

LDLIBS += -lpng
LDLIBS += -lz

CFLAGS += -std=c17 -Wall -Werror

BREW_PREFIX := $(shell brew --prefix)
ifdef BREW_PREFIX
CFLAGS += -I$(BREW_PREFIX)/include
LDFLAGS += -L$(BREW_PREFIX)/lib
endif

all: png2c

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
# on-create is currently Linux-only, uses inotify
all: on-create
endif

compile_flags.txt: Makefile
	echo "$(CFLAGS) $(LDFLAGS)" | tr ' ' '\n' > $@

.PHONY: clean
clean:
	rm -f on-create png2c
