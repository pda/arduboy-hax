#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "display.h"
#include "spi.h"
#include "game.h"
#include "led.h"

#include "images/pda.h"

int main() {
  led_init();
  spi_init();
  display_init();

  display_image(images_pda_png);
  _delay_ms(500);
  //display_scroll_start();
  //_delay_ms(1900);
  //display_scroll_stop();
  //_delay_ms(1000);

  PORTF |= 0b11110000; // d-pad pull-ups
  PORTE |= 1<<6; // A pull-up
  PORTB |= 1<<4; // B pull-up

  game();

  // d-pad controls RGB LED
  // while (1) {
  //   !(PINF & 1<<5) ? LED_ON(red) : LED_OFF(red); // L
  //   !(PINF & 1<<6) ? LED_ON(green) : LED_OFF(green); // R
  //   !(PINF & 1<<4) ? LED_ON(blue) : LED_OFF(blue); // D
  // }
}
