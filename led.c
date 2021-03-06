#include "led.h"

void led_init() {
  led_red = (struct led_t){.port = &PORTB, .ddr = &DDRB, .mask = 1<<6};
  led_green = (struct led_t){.port = &PORTB, .ddr = &DDRB, .mask = 1<<7};
  led_blue = (struct led_t){.port = &PORTB, .ddr = &DDRB, .mask = 1<<5};

  LED_INIT(led_red); LED_OFF(led_red);
  LED_INIT(led_green); LED_OFF(led_green);
  LED_INIT(led_blue); LED_OFF(led_blue);
}
