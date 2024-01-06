#include "led.h"

// These are `extern struct` in led.h
struct led_t led_red;
struct led_t led_green;
struct led_t led_blue;

void led_init() {
#if __AVR__
  led_red = (struct led_t){.port = &PORTB, .ddr = &DDRB, .mask = 1<<6};
  led_green = (struct led_t){.port = &PORTB, .ddr = &DDRB, .mask = 1<<7};
  led_blue = (struct led_t){.port = &PORTB, .ddr = &DDRB, .mask = 1<<5};

  LED_INIT(led_red); LED_OFF(led_red);
  LED_INIT(led_green); LED_OFF(led_green);
  LED_INIT(led_blue); LED_OFF(led_blue);
#endif
}
