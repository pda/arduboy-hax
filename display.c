#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdbool.h>

#include "display.h"
#include "spi.h"

static uint8_t display_buffer[SSD1306_PAGES * SSD1306_COLS];
static uint8_t dirty_page_min, dirty_page_max, dirty_col_min, dirty_col_max;

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
  // clear buffer
  for (int i = 0; i < sizeof(display_buffer); i++) {
    display_buffer[i] = 0x00;
  }
  // mark entire buffer dirty; unknown OLED RAM state
  display_set_dirty();
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

void display_set_dirty() {
  // mark entire buffer dirty; unknown OLED RAM state
  dirty_page_min = 0;
  dirty_page_max = SSD1306_PAGE_MAX;
  dirty_col_min = 0;
  dirty_col_max = SSD1306_COL_MAX;
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

struct sprite_t {
  uint8_t data[8];
  uint8_t x;
  uint8_t y;
  int32_t x_vel;
  int32_t y_vel;
  bool gnd;
  int8_t jmp;
};

void display_test_things() {
  // background
  for (int i = 0; i < sizeof(display_buffer); i += 16) {
    display_buffer[i+8] = 0x08;
    display_buffer[i+9] = 0x10;
  }
  // floor
  for (int i = 7*SSD1306_COLS; i < sizeof(display_buffer); i++) {
    display_buffer[i] = 0xAA;
  }
  display_set_dirty();
  display_draw_buffer();

  struct sprite_t player = {
    .data = {0x00, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x00},
    .x = 8,
    .y = 48,
    .x_vel = 0,
    .y_vel = 0,
    .gnd = true,
    .jmp = 0,
  };

  while (1) {
    // gravity-ish
    if (!player.gnd) {
      player.y_vel += 6;
    }

    // slow down x
    if (player.x_vel > 0) {
      player.x_vel -= 8;
    } else if (player.x_vel < 0) {
      player.x_vel += 8;
    }

    // jump
    if ((PINB & 1<<4) == 0) {
      if (player.gnd && !player.jmp) {
        player.gnd = false;
        player.jmp = 10;
      }
      if (player.jmp > 1) {
        if (player.jmp % 2 == 0) {
          player.y_vel -= (player.jmp * 5);
        }
        player.jmp--;
      }
    } else {
      player.jmp = 0; // ready for next jump
    }

    if ((PINF & 1<<5) == 0 && player.x_vel > -64) { // left
      player.x_vel -= 16;
    }
    if ((PINF & 1<<6) == 0 && player.x_vel < 64) { // right
      player.x_vel += 16;
    }

    // apply velocity
    player.x += (player.x_vel / 32);
    player.y += (player.y_vel / 32);


    // floor detection
    if (player.y >= 48) {
      player.y_vel = 0;
      player.y = 48;
      player.gnd = true;
    }

    // side-walls
    if (player.x > 128+64) { // wrapped?
      player.x = 0;
    } else if (player.x + sizeof(player.data) > 128) {
      player.x = 128-sizeof(player.data);
    }

    // TODO: much optimization
    display_set_dirty();
    display_draw_buffer();

    // select address window
    display_select_cmd();
    spi_send_8(SSD1306_SETCOLUMNADDR);
    spi_send_8(player.x);
    uint8_t col_hi = player.x + sizeof(player.data);
    if (col_hi > SSD1306_COL_MAX) {
      col_hi = SSD1306_COL_MAX;
    }
    spi_send_8(col_hi);
    spi_send_8(SSD1306_SETPAGEADDR);
    spi_send_8(player.y / 8);
    uint8_t page_hi = player.y / 8 + sizeof(player.data);
    if (page_hi > SSD1306_PAGE_MAX) {
      page_hi = SSD1306_PAGE_MAX;
    }
    spi_send_8(page_hi);

    // send updated display bytes
    display_select_data();
    for (int i = 0; i < sizeof(player.data); i++) {
      spi_send_8(player.data[i]);
    }
    _delay_ms(10);
  }
}
