#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "display.h"
#include "spi.h"

#include "images/pda.h"

struct led_t {
  volatile uint8_t * port;
  volatile uint8_t * ddr;
  uint8_t mask;
};
#define LED_INIT(led) (*led.ddr |= led.mask)
#define LED_ON(led) (*led.port &= ~led.mask)
#define LED_OFF(led) (*led.port |= led.mask)

int main() {
  struct led_t red = {.port = &PORTB, .ddr = &DDRB, .mask = 1<<6};
  struct led_t green = {.port = &PORTB, .ddr = &DDRB, .mask = 1<<7};
  struct led_t blue = {.port = &PORTB, .ddr = &DDRB, .mask = 1<<5};
  LED_INIT(red); LED_OFF(red);
  LED_INIT(green); LED_OFF(green);
  LED_INIT(blue); LED_OFF(blue);

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
  display_test_things();

  // d-pad controls RGB LED
  while (1) {
    !(PINF & 1<<5) ? LED_ON(red) : LED_OFF(red); // L
    !(PINF & 1<<6) ? LED_ON(green) : LED_OFF(green); // R
    !(PINF & 1<<4) ? LED_ON(blue) : LED_OFF(blue); // D
  }
}
