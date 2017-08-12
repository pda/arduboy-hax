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
