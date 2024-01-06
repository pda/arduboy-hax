#if __AVR__
#include <avr/io.h>
#include <util/delay.h>
#endif

#include <stdint.h>

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

#if __AVR__
  PORTF |= 0b11110000; // d-pad pull-ups
  PORTE |= 1<<6; // A pull-up
  PORTB |= 1<<4; // B pull-up
#endif

  game();

#if __AVR__
  // (unreachable)
  // d-pad controls RGB LED
  while (1) {
    !(PINF & 1<<5) ? LED_ON(led_red) : LED_OFF(led_red); // L
    !(PINF & 1<<6) ? LED_ON(led_green) : LED_OFF(led_green); // R
    !(PINF & 1<<4) ? LED_ON(led_blue) : LED_OFF(led_blue); // D
  }
#endif
}
