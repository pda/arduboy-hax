#pragma once
#if __AVR__
#include <avr/pgmspace.h>
#endif
//  0|  # # # # #   # # |
//  1|  #   # # # # #   |
//  2|    # # #         |
//  3|          #       |
//  4|      #           |
//  5|  #               |
//  6|                  |
//  7|                  |
const uint8_t PROGMEM images_plat_right_png[] = {
  0x23, 0x05, 0x17, 0x07, 0x0B, 0x02, 0x03, 0x01, };
