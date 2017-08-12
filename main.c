#include <avr/io.h>
#include <stdint.h>

#include "display.h"
#include "spi.h"

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
  LED_INIT(red);
  LED_INIT(green);
  LED_INIT(blue);

  spi_init();
  display_init();

  // test pattern
  display_select_data();
  for (int i = 0; i < (128*64/8); i++) {
    spi_send_8((uint8_t)i);
  }
  display_deselect();

  // d-pad controls RGB LED
  PORTF |= 0b11110000; // d-pad pull-ups
  while (1) {
    !(PINF & 1<<5) ? LED_ON(red) : LED_OFF(red); // L
    !(PINF & 1<<6) ? LED_ON(green) : LED_OFF(green); // R
    !(PINF & 1<<4) ? LED_ON(blue) : LED_OFF(blue); // D
  }
}
