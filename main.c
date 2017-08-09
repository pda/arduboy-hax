#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

/********************
Arduboy  Arduino  AVR
---------------------
LEFT       A2     PF5
RIGHT      A1     PF6
UP         A0     PF7
DOWN       A3     PF4
A           7     PE6
B           8     PB4

RED        10     PB6
GREEN      11     PB7
BLUE        9     PB5

SPKR_1      5     PC6
SPKR_2     13     PC7
---------------------
********************/

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

  PORTF |= 0b11110000; // d-pad pull-ups

  while (1) {
    !(PINF & 1<<5) ? LED_ON(red) : LED_OFF(red); // L
    !(PINF & 1<<6) ? LED_ON(green) : LED_OFF(green); // R
    !(PINF & 1<<4) ? LED_ON(blue) : LED_OFF(blue); // D
  }
}
