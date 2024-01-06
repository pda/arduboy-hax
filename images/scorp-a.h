#pragma once
#if __AVR__
#include <avr/pgmspace.h>
#endif
//  0|                  |
//  1|                  |
//  2|              #   |
//  3|                # |
//  4|  # #         #   |
//  5|      # # # # #   |
//  6|  # #   #   #     |
//  7|        #   #     |
const uint8_t PROGMEM images_scorp_a_png[] = {
  0x50, 0x50, 0x20, 0xE0, 0x20, 0xE0, 0x34, 0x08, };
