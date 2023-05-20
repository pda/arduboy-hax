#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdbool.h>
#include <string.h>

#include "display.h"
#include "spi.h"
#include "led.h"

// private headers
uint8_t min_uint8(uint8_t a, uint8_t b);
uint8_t max_uint8(uint8_t a, uint8_t b);

static uint8_t dirty_page_min, dirty_page_max, dirty_col_min, dirty_col_max;

uint8_t display_buffer[DISPLAY_BUFFER_SIZE];

// https://github.com/Arduboy/Arduboy/blob/3c409fef/src/core/core.cpp#L25
const uint8_t display_init_program[] = {
  SSD1306_SETDISPLAYCLOCKDIV, 0xF0, // default 0x80
  SSD1306_CHARGEPUMP, 0x14, // 0x14 = enable, default is disabled
  SSD1306_SEGMENTREMAP | 0x01, // default is 0x00
  SSD1306_COMSCANDEC,
  SSD1306_SETCONTRAST, 0xCF,
  SSD1306_SETPRECHARGE, 0xF1,
  SSD1306_DISPLAYON,
  SSD1306_MEMORYMODE, 0x00, // horizontal addressing mode (0x00)
};

void display_init() {
  DDRD |= (   // outputs:
      (1<<4)| // DC
      (1<<6)| // CS
      (1<<7)| // RST
      0);

  PORTD |= 1<<7; // reset high
  _delay_ms(1);
  PORTD &= ~(1<<7); // reset active low
  _delay_ms(10);
  PORTD |= 1<<7; // reset high

  display_select_cmd();
  for (int8_t i = 0; i < sizeof(display_init_program); i++) {
    spi_send_8(display_init_program[i]);
  }
  display_clear_buffer();
  display_set_dirty(); // unknown OLED RAM state
}

uint8_t * display_get_buffer() {
  return display_buffer;
}

void display_clear_buffer() {
  for (int i = 0; i < sizeof(display_buffer); i++) {
    display_buffer[i] = 0x00;
  }
}

void display_load_buffer(const uint8_t * src) {
  memcpy(display_buffer, src, sizeof(display_buffer));
}

void display_draw_buffer() {
  if (dirty_page_min > dirty_page_max || dirty_col_min > dirty_col_max) {
    return;
  }
  // select address window
  display_select_cmd();
  spi_send_8(SSD1306_SETCOLUMNADDR);
  spi_send_8(dirty_col_min);
  spi_send_8(dirty_col_max);
  spi_send_8(SSD1306_SETPAGEADDR);
  spi_send_8(dirty_page_min);
  spi_send_8(dirty_page_max);

  // send updated display bytes
  display_select_data();
  for (uint8_t page = dirty_page_min; page <= dirty_page_max; page++) {
    for (uint8_t col = dirty_col_min; col <= dirty_col_max; col++) {
      spi_send_8(display_buffer[(page * SSD1306_COLS) + col]);
    }
  }
  display_set_clean();
}

void display_image(const uint8_t * src) {
  display_select_cmd();
  spi_send_8(SSD1306_SETCOLUMNADDR);
  spi_send_8(0);
  spi_send_8(SSD1306_COL_MAX);
  spi_send_8(SSD1306_SETPAGEADDR);
  spi_send_8(0);
  spi_send_8(SSD1306_PAGE_MAX);
  display_select_data();
  for (int i = 0; i < sizeof(display_buffer); i++) {
    spi_send_8(pgm_read_byte(src + i));
  }
  display_set_dirty();
}

void display_px(uint8_t x, uint8_t y, uint8_t on) {
  uint8_t page = (y / 8);
  uint8_t col = x;

  if (page < dirty_page_min) dirty_page_min = page;
  if (page > dirty_page_max) dirty_page_max = page;
  if (col < dirty_col_min) dirty_col_min = col;
  if (col > dirty_col_max) dirty_col_max = col;

  if (dirty_col_max >= 128) {
    LED_ON(led_red);
  }

  uint16_t offset = (page * DISPLAY_WIDTH) + col;
  uint8_t mask = (1 << (y % 8));
  if (on) {
    display_buffer[offset] |= mask;
  } else {
    display_buffer[offset] &= ~mask;
  }
}

void display_select_cmd() {
  PORTD &= ~(1<<6); // CS active low
  PORTD &= ~(1<<4); // DC low (cmd)
}

void display_select_data() {
  PORTD &= ~(1<<6); // CS active low
  PORTD |= 1<<4; // DC high (data)
}

void display_deselect() {
  PORTD |= 1<<6; // CS high
}

void display_set_clean() {
  dirty_page_min = SSD1306_PAGE_MAX;
  dirty_page_max = 0;
  dirty_col_min = SSD1306_COL_MAX;
  dirty_col_max = 0;
}

void display_set_dirty() {
  dirty_page_min = 0;
  dirty_page_max = SSD1306_PAGE_MAX;
  dirty_col_min = 0;
  dirty_col_max = SSD1306_COL_MAX;
}

void display_set_dirty_sprite(struct sprite_t s) {
  uint8_t page_top = min_uint8(s.y, s.y_prev) / 8;
  uint8_t page_bot = (max_uint8(s.y, s.y_prev) + 8) / 8;
  uint8_t col_l = min_uint8(s.x, s.x_prev);
  uint8_t col_r = max_uint8(s.x, s.x_prev) + 8;

  if (page_top < dirty_page_min) dirty_page_min = page_top;
  if (page_bot > dirty_page_max) dirty_page_max = page_bot;
  if (col_l < dirty_col_min) dirty_col_min = col_l;
  if (col_r > dirty_col_max) dirty_col_max = col_r;
}

uint8_t min_uint8(uint8_t a, uint8_t b) {
  if (b < a) {
    return b;
  } else {
    return a;
  }
}

uint8_t max_uint8(uint8_t a, uint8_t b) {
  if (b > a) {
    return b;
  } else {
    return a;
  }
}

void display_scroll_start() {
  display_select_cmd();
  spi_send_8(SSD1306_CONTSCROLLVH | 0b1);
  spi_send_8(0x00); // A: dummy
  spi_send_8(0x00); // B: start page 0-7
  spi_send_8(0x07); // C: time interval
  spi_send_8(0x07); // D: end page 0-7 (D>B)
  spi_send_8(0x02); // E: v-offset
  spi_send_8(SSD1306_ACTIVATESCROLL);
}

void display_scroll_stop() {
  display_select_cmd();
  spi_send_8(SSD1306_DEACTIVATESCROLL);
}

void sprite_move(struct sprite_t * s, uint8_t x, uint8_t y) {
  s->x_prev = s->x;
  s->y_prev = s->y;
  s->x = x;
  s->y = y;
}
