#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <png.h>
#include <zlib.h>

void png_error_fn(png_structp png_ptr, png_const_charp foo);

int main(int argc, char **argv) {
  if (argc < 2) {
    puts("Usage: not that.");
    exit(1);
  }
  char * filename = argv[1];

  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    perror("fopen");
    exit(1);
  }

  const int sig_bytes = 8;
  uint8_t header[8];
  if (fread(header, 1, sig_bytes, fp) != sig_bytes) {
    perror("fread");
    exit(1);
  }
  if (!png_check_sig(header, sig_bytes)) {
    fprintf(stderr, "invalid PNG signature\n");
  }

  png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, &png_error_fn, NULL);
  if (!png_ptr) {
    fprintf(stderr, "png_create_read_struct failed");
    exit(1);
  }

  png_infop png_info_ptr = png_create_info_struct(png_ptr);
  if (!png_info_ptr) {
    png_destroy_read_struct(&png_ptr, NULL, NULL);
    fprintf(stderr, "png_create_info_struct failed");
    exit(1);
  }

  png_init_io(png_ptr, fp);
  png_set_sig_bytes(png_ptr, sig_bytes);
  png_set_user_limits(png_ptr, 128, 64);
  png_read_png(png_ptr, png_info_ptr, PNG_TRANSFORM_EXPAND, NULL);

  png_uint_32 width, height;
  int bit_depth, color_type;
  png_get_IHDR(png_ptr, png_info_ptr, &width, &height, &bit_depth, &color_type, NULL, NULL, NULL);
  bool has_palette = color_type & PNG_COLOR_MASK_PALETTE;
  bool has_color = color_type & PNG_COLOR_MASK_COLOR;
  bool has_alpha = color_type & PNG_COLOR_MASK_ALPHA;

  fprintf(
    stderr,
    "png2c transformed source: %lux%lu %d-bit palette:%s color:%s alpha:%s\n",
    (unsigned long)width,
    (unsigned long)height,
    bit_depth,
    has_palette ? "yes" : "no",
    has_color ? "yes" : "no",
    has_alpha ? "yes" : "no"
  );
  if (color_type != PNG_COLOR_TYPE_RGB) {
    fprintf(stderr, "expected 24-bit RGB after PNG_TRANSFORM_EXPAND");
    exit(1);
  }

  uint8_t target_data[width * height / 8];
  uint8_t *target_byte = target_data;

  png_bytepp row_pointers = png_get_rows(png_ptr, png_info_ptr);
  for (int y = 0; y < height; y += 8) {
    for (int x = 0; x < width; x++) {
      int i = x * 3; // offset of 24-bit RGB data in row
      *target_byte = 0x00;
      for (int bit = 0; bit <= 7; bit++) {
        png_bytep row = row_pointers[y + bit];
        if (row[i] | row[i+1] | row[i+2]) {
          *target_byte |= (1<<bit);
        }
      }
      target_byte++;
    }
  }
  png_destroy_read_struct(&png_ptr, &png_info_ptr, NULL);

  char *var_name = strdup(filename);
  if (var_name == NULL) {
    perror("strdup");
    exit(1);
  }
  char *var_name_p = var_name;
  while (*var_name_p) {
    char c = *var_name_p;
    if ((c < 'a' || c > 'z') && (c < '0' || c > '9')) {
      *var_name_p = '_';
    }
    var_name_p++;
  }
  printf("#include <avr/pgmspace.h>\n");
  printf("const uint8_t PROGMEM %s[] = {\n", var_name);
  for (int i = 0; i < sizeof(target_data); i++) {
    if (i % 16 == 0) {
      printf("  ");
    }
    printf("0x%02x,", target_data[i]);
    putchar(i % 16 == 15 ? '\n' : ' ');
  }
  printf("};\n");
}


void png_error_fn(png_structp png_ptr, png_const_charp foo) {
  fprintf(stderr, "PNG error: %s\n", foo);
  exit(1);
}
