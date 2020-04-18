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
    perror("failed to read signature; fread");
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

  char * color_type_name;
  switch (color_type) {
    case PNG_COLOR_TYPE_GRAY: color_type_name = "PNG_COLOR_TYPE_GRAY"; break;
    case PNG_COLOR_TYPE_GRAY_ALPHA: color_type_name= "PNG_COLOR_TYPE_GRAY_ALPHA"; break;
    case PNG_COLOR_TYPE_PALETTE: color_type_name= "PNG_COLOR_TYPE_PALETTE"; break;
    case PNG_COLOR_TYPE_RGB: color_type_name= "PNG_COLOR_TYPE_RGB"; break;
    case PNG_COLOR_TYPE_RGB_ALPHA: color_type_name= "PNG_COLOR_TYPE_RGB_ALPHA"; break;
    default: color_type_name = "unknown";
  }

  fprintf(
    stderr,
    "png2c transformed source: %lux%lu type:%s depth:%d palette:%s color:%s alpha:%s\n",
    (unsigned long)width,
    (unsigned long)height,
    color_type_name,
    bit_depth,
    has_palette ? "yes" : "no",
    has_color ? "yes" : "no",
    has_alpha ? "yes" : "no"
  );
  if (color_type != PNG_COLOR_TYPE_RGB && color_type != PNG_COLOR_TYPE_GRAY) {
    fprintf(stderr, "expected grayscale or 24-bit RGB after PNG_TRANSFORM_EXPAND");
    exit(1);
  }

  uint8_t target_data[width * height / 8];
  uint8_t *target_byte = target_data;

  png_bytepp row_pointers = png_get_rows(png_ptr, png_info_ptr);
  for (int y = 0; y < height; y += 8) {
    for (int x = 0; x < width; x++) {
      *target_byte = 0x00;
      for (int bit = 0; bit <= 7; bit++) {
        if (y+bit >= height) continue; // image height not divisible by 8
        png_bytep row = row_pointers[y + bit];
        char pixel_on;
        switch (color_type) {
          case PNG_COLOR_TYPE_RGB: // 24-bit (three byte) RGB data
            pixel_on = row[x*3] | row[x*3 + 1] | row[x*3 + 2];
            break;
          case PNG_COLOR_TYPE_GRAY:
            pixel_on = row[x];
            break;
        }
        if (pixel_on) {
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
  for (int y = 0; y < height; y++) {
    printf("//%3d| ", y);
    for (int x = 0; x < width; x++) {
      int offset = x + y/8*width;
      if (target_data[offset] & (1 << (y%8))) {
        printf(" #");
      } else {
        printf("  ");
      }
    }
    printf(" |\n");
  }
  printf("const uint8_t PROGMEM %s[] = {\n", var_name);
  for (int i = 0; i < sizeof(target_data); i++) {
    if (i % 16 == 0) {
      printf("  ");
    }
    printf("0x%02X,", target_data[i]);
    putchar(i % 16 == 15 ? '\n' : ' ');
  }
  printf("};\n");
}


void png_error_fn(png_structp png_ptr, png_const_charp foo) {
  fprintf(stderr, "PNG error: %s\n", foo);
  exit(1);
}
