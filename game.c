#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// wdt needs monkey-patching for clang when _WD_CONTROL_REG is >= 0x60
// i.e. for ATmega32U4
#include "avr-wdt.h"

#include "game.h"
#include "display.h"

#include "images/plat.h"
#include "images/plat-left.h"
#include "images/plat-right.h"

uint8_t background_buffer[DISPLAY_BUFFER_SIZE];

void game() {
  // floor
  for (int i = 7*SSD1306_COLS; i < DISPLAY_BUFFER_SIZE; i += sizeof(images_plat_png)) {
    memcpy(background_buffer + i, images_plat_png, sizeof(images_plat_png));
  }
  // platform
  for (int i = 0; i < 4; i++) {
    const uint8_t * tile;
    switch (i) {
      case 0: tile = images_plat_left_png; break;
      case 3: tile = images_plat_right_png; break;
      default: tile = images_plat_png; break;
    }
    memcpy(background_buffer + 2*SSD1306_COLS + 24 + i*8, tile, sizeof(images_plat_png));
  }
  // platform
  for (int i = 0; i < 6; i++) {
    const uint8_t * tile;
    switch (i) {
      case 0: tile = images_plat_left_png; break;
      case 5: tile = images_plat_right_png; break;
      default: tile = images_plat_png; break;
    }
    memcpy(background_buffer + 4*SSD1306_COLS + 48 + i*8, tile, sizeof(images_plat_png));
  }
  display_set_dirty();

  struct sprite_t player = {
    .frames = {
      {0x00, 0x20, 0xF0, 0x3E, 0xFA, 0x2C, 0x00, 0x00}, // ==> images/player-a.h <==
      {0x00, 0x90, 0x70, 0x3E, 0xFA, 0x4C, 0x00, 0x00}, // ==> images/player-b.h <==
      {0x00, 0x20, 0xF0, 0x3E, 0xFA, 0x2C, 0x00, 0x00}, // ==> images/player-a.h <==
      {0x00, 0x90, 0x70, 0x3E, 0xFA, 0x4C, 0x00, 0x00}, // ==> images/player-b.h <==
      {0x00, 0x88, 0x64, 0x3F, 0xBD, 0x66, 0x01, 0x00}, // ==> images/jump-up.h <==
      {0x04, 0x84, 0x64, 0x3F, 0xBD, 0x66, 0x02, 0x02}, // ==> images/jump-apex.h <==
      {0x00, 0x81, 0x62, 0x3C, 0xBA, 0x66, 0x01, 0x00}, // ==> images/jump-down.h <==
      {0x00, 0x00, 0x80, 0xE0, 0x70, 0x68, 0xD8, 0x00}, // ==> images/player-crouch.h <==
    },
    .x = 8,
    .y = 8,
    .x_vel = 0,
    .y_vel = 0,
    .gnd = false,
    .jmp = 0,
  };
  player.frame = player.frames[0];

  while (1) {
    int x_new = (int)player.x;
    int y_new = (int)player.y;

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

    // up+down == reset
    if ((PINF & (1<<4 | 1<<5 | 1<<6 | 1<<7)) == 0b01100000) {
      // https://github.com/arduino/ArduinoCore-avr/blob/eabd762a1edcf076877b7bec28b7f99099141473/cores/arduino/USBCore.h#L287-L298
      cli();
      *(uint8_t *)0x0800 = 0x77;
      *(uint8_t *)0x0801 = 0x77;
      wdt_reset();
      WDTCSR = (_BV(WDCE) | _BV(WDE));
      WDTCSR = _BV(WDE);
      while (true) { }
    }

    // crouch
    player.crouch = (PINF & 1<<4) == 0 && !player.jmp && player.x_vel == 0;

    if ((PINF & 1<<5) == 0 && player.x_vel > -64) { // left
      player.x_vel -= 16;
      player.flip = true;
    }
    if ((PINF & 1<<6) == 0 && player.x_vel < 64) { // right
      player.x_vel += 16;
      player.flip = false;
    }

    // apply velocity
    x_new += (player.x_vel / 32);
    y_new += (player.y_vel / 32);

    // floor detection
    if (y_new >= 48) {
      player.y_vel = 0;
      y_new = 48;
      player.gnd = true;
    }

    // side-walls
    if (x_new < 0) {
      x_new = 0;
    } else if (x_new > 128-8) {
      x_new = 128-8;
    }

    sprite_move(&player, (uint8_t)x_new, (uint8_t)y_new);

    // sprite frame selector
    if (player.y_vel > 48) {
      player.frame = player.frames[4]; // jump-up
    } else if (player.y_vel < -48) {
      player.frame = player.frames[6]; // jump-down
    } else if (player.jmp) {
      player.frame = player.frames[5]; // jump-apex
    } else if (player.crouch) {
      player.frame = player.frames[7]; // player-crouch
    } else if (player.x_vel != 0) {
      player.frame = player.frames[1]; // player-b
    } else {
      player.frame = player.frames[0]; // player-a
    }

    display_load_buffer(background_buffer);
    //memcpy(display_buffer, background_buffer, sizeof(background_buffer));
    //memcpy(display_buffer + player.x, *player.frame, sizeof(*player.frame));

    uint8_t * display_buffer = display_get_buffer();

    int row = player.y / 8;
    uint8_t bit_offset = player.y % 8;
    // uint8_t bit_mask = 0xFF >> bit_offset;
    for (int sprx = 0; sprx < 8; sprx++) {
      for (int spry = 0; spry < 8; spry++) {
        uint8_t * slice_a = display_buffer + (row * SSD1306_COLS) + player.x + sprx;
        uint8_t * slice_b = slice_a + SSD1306_COLS;
        if (player.flip) sprx = 7 - sprx;
        // opaque:
        // *slice_a = (*slice_a & bit_mask) | (*player.frame[sprx] << bit_offset);
        // *slice_b = (*slice_b & ~bit_mask) | (*player.frame[sprx] >> (8 - bit_offset));
        // transparent:
        *slice_a |= *(player.frame + sprx) << bit_offset;
        *slice_b |= *(player.frame + sprx) >> (8 - bit_offset);
      }
    }
    display_set_dirty_sprite(player);

    display_draw_buffer();

    _delay_ms(10);
  }
}
