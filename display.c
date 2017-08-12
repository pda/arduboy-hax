#include <avr/io.h>
#include <util/delay.h>

#include "display.h"
#include "spi.h"

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

uint8_t dirty_page_min, dirty_page_max, dirty_col_min, dirty_col_max;

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

  // clear display
  display_select_data();
  for (int i = 0; i < sizeof(display_buffer); i++) {
    spi_send_8(0x00);
  }

  // clear buffer
  for (int i = 0; i < sizeof(display_buffer); i++) {
    display_buffer[i] = 0x00;
  }
  // mark entire buffer dirty; unknown OLED RAM state
  dirty_page_min = 0;
  dirty_page_max = SSD1306_PAGE_MAX;
  dirty_col_min = 0;
  dirty_col_max = SSD1306_COL_MAX;
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
  // clear dirty state
  dirty_page_min = SSD1306_PAGE_MAX;
  dirty_page_max = 0;
  dirty_col_min = SSD1306_COL_MAX;
  dirty_col_max = 0;
}

void display_px(uint8_t x, uint8_t y, uint8_t on) {
  uint8_t page = (y / 8);
  uint8_t col = x;

  if (page < dirty_page_min) dirty_page_min = page;
  if (page > dirty_page_max) dirty_page_max = page;
  if (col < dirty_col_min) dirty_col_min = col;
  if (col > dirty_col_max) dirty_col_max = col;

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
