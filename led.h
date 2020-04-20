#pragma once
#include <avr/io.h>

struct led_t {
  volatile uint8_t * port;
  volatile uint8_t * ddr;
  uint8_t mask;
};

#define LED_INIT(led) (*led.ddr |= led.mask)
#define LED_ON(led) (*led.port &= ~led.mask)
#define LED_OFF(led) (*led.port |= led.mask)

struct led_t led_red;
struct led_t led_green;
struct led_t led_blue;

void led_init();
