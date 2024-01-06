#pragma once
#if __AVR__
#include <avr/pgmspace.h>
#endif
//  0|                  |
//  1|        # #       |
//  2|        #   #     |
//  3|        # # #     |
//  4|      # # #       |
//  5|    # # # # #     |
//  6|      #   #       |
//  7|      #   #       |
const uint8_t PROGMEM images_player_a_png[] = {
  0x00, 0x20, 0xF0, 0x3E, 0xFA, 0x2C, 0x00, 0x00, };
