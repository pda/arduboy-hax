#include <stdbool.h>
#include <util/delay.h>

#include "game.h"
#include "display.h"
// TODO: don't include SPI
#include "spi.h"

#include "images/mockup.h"

void game() {
  display_image(images_mockup_png);
  _delay_ms(2000);

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

  struct sprite_t player = {
    .data = {0x00, 0x88, 0x64, 0x3F, 0xBD, 0x66, 0x01, 0x00},
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
