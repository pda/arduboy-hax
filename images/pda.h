#pragma once
#if __AVR__
#include <avr/pgmspace.h>
#endif
//  0|                                  #   #   #   #   #                                               #   #   #   #   #                                               #   #   #   #   #                                               #   #   #   #   #               |
//  1|                                                                                                                                                                                                                                                                  |
//  2|                              #                       #                                       #                       #                                       #                       #                                       #                       #           |
//  3|                                                                                                                                                                                                                                                                  |
//  4|                          #                               #                               #                               #                               #                               #                               #                               #       |
//  5|                                                                                                                                                                                                                                                                  |
//  6|                      #                                       #                       #                         # # #         #                       #                                       #                       #                                       #   |
//  7|                                                                                                              # # # # #                                                                                                                                           |
//  8|  #   #   #   #   #                                               #   #   #   #   #                           # # # # # #         #   #   #   #   #                                               #   #   #   #   #                                               |
//  9|                                                                                                              # # # # # # #                                                                                                                                       |
// 10|                      #                                       #                       #                         # # # # # # # #                       #                                       #                       #                                       #   |
// 11|                                                                                                                  # # # # # # #                                                                                                                                   |
// 12|                          #                               #                               #                         # # # # # # #                         #                               #                               #                               #       |
// 13|                                                                                                                      # # # # # # #                                                                                                                               |
// 14|                              #                       #                                       #                       # # # # # # # #                         #                       #                                       #                       #           |
// 15|                                                                                                                          # # # # # # #                                                                                                                           |
// 16|                                  #   #   #   #   #                                               #   #   #   #   #         # # # # # # #                         #   #   #   #   #                                               #   #   #   #   #               |
// 17|                                                                                                                              # # # # # # #                                                                                                                       |
// 18|                              #                       #                                       #                       #         # # # # # # #                 #                       #                                       #                       #           |
// 19|                                                                                                                                  # # # # # # #                                                                                                                   |
// 20|                          #                               #                               #                               #         # # # # # # #         #                               #                               #                               #       |
// 21|                                                                                                                                      # # # # # # #                                                                                                               |
// 22|                      #                                       #                       #                                       # # # # # # # # # # # # #                                       #                       #                                       #   |
// 23|                                                                                                                              # # # # # # # # # # # # #                                                                                                           |
// 24|  #   #   #   #   #                                               #   #   #   #   #                                         # # # # # # # # # # # # # # #                                         #   #   #   #   #                                               |
// 25|                                                                                                                          # # # # # # # # # # # # # # # # #                                                                                                       |
// 26|                      #                                       #                       #                                 # # # # # # # # # # # # # # # # # # #           # # #                 #                       #                                       #   |
// 27|                                                                                                                      # # # # # # #               # # # # # # #       # # # # #                                                                                   |
// 28|                          #                               #                               #                         # # # # # # #                   # # # # # # #     # # # # # #         #                               #                               #       |
// 29|                                                                                                                  # # # # # # #                       # # # # # # #   # # # # # # #                                                                               |
// 30|                              #                       #                                       # # # # # # # # # # # # # # # #                           # # # # # # # # # # # # # # # #                                       #                       #           |
// 31|                                                                                              # # # # # # # # # # # # # # #                               # # # # # # # # # # # # # # #                                                                           |
// 32|                                  #   #   #   #   #                                         # # # # # # # # # # # # # # #                                   # # # # # # # # # # # # # # #                                         #   #   #   #   #               |
// 33|                                                                                          # # # # # # # # # # # # # # # # #                               # # # # # # # # # # # # # # # # #                                                                       |
// 34|                              #                       #                                 # # # # # # # # # # # # # # # # # # #                           # # # # # # # # # # # # # # # # # # #                                 #                       #           |
// 35|                                                                                      # # # # # # #               # # # # # # #                       # # # # # # #               # # # # # # #                                                                   |
// 36|                          #                               #                         # # # # # # #                   # # # # # # #                   # # # # # # #                   # # # # # # #                         #                               #       |
// 37|                                                                                  # # # # # # #                       # # # # # # #               # # # # # # #                       # # # # # # #                                                               |
// 38|                      #                                       #                 # # # # # # #                           # # # # # # # # # # # # # # # # # # #                           # # # # # # #                 #                                       #   |
// 39|                                                                              # # # # # # #                               # # # # # # # # # # # # # # # # #                               # # # # # # #                                                           |
// 40|  #   #   #   #   #                                               #   #   # # # # # # # #                                   # # # # # # # # # # # # # # #                                   # # # # # # # #   #   #                                               |
// 41|                                                                          # # # # # # # # #                               # # # # # # # # # # # # # # # # #                               # # # # # # # # #                                                       |
// 42|                      #                                       #         # # # # # # # # # # #                           # # # # # # # # # # # # # # # # # # #                           # # # # # # # # # # #         #                                       #   |
// 43|                                                                      # # # # # # # # # # # # #                       # # # # # # #               # # # # # # #                       # # # # # # # # # # # # #                                                   |
// 44|                          #                               #         # # # # # # #   # # # # # # #                   # # # # # # #                   # # # # # # #                   # # # # # # #   # # # # # #           #                               #       |
// 45|                                                                  # # # # # # #       # # # # # # #               # # # # # # #                       # # # # # # #               # # # # # # #       # # # # #                                                   |
// 46|                              #                       #         # # # # # # #           # # # # # # # # # # # # # # # # # # #                           # # # # # # # # # # # # # # # # # # #           # # #                 #                       #           |
// 47|                                                              # # # # # # #               # # # # # # # # # # # # # # # # #                               # # # # # # # # # # # # # # # # #                                                                       |
// 48|                                  #   #   #   #   #         # # # # # # #                   # # # # # # # # # # # # # # #                                   # # # # # # # # # # # # # # #                                         #   #   #   #   #               |
// 49|                                                          # # # # # # #                       # # # # # # # # # # # # #       # #       #     # #   # # #     # # # # # # # # # # # # #                                                                           |
// 50|                              #                       # # # # # # # #                         # # # # # # # # # # # # #           #   #   #     #       #     # # # # # # # # # # # # #                                       #                       #           |
// 51|                                                      # # # # # # #                                                             #     #   #     #     #                                                                                                           |
// 52|                          #                         # # # # # # #                         #                                   #       #   #     #     #                                   #                               #                               #       |
// 53|                                                  # # # # # # #                                                               # # #     #       #     #                                                                                                           |
// 54|                      #                         # # # # # # # #                       #                                                                                                       #                       #                                       #   |
// 55|                                              # # # # # # #                                                                                                                                                                                                       |
// 56|  #   #   #   #   #                           # # # # # #         #   #   #   #   #                                               #   #   #   #   #                                               #   #   #   #   #                                               |
// 57|                                              # # # # #                                                                                                                                                                                                           |
// 58|                      #                         # # #         #                       #                                       #                       #                                       #                       #                                       #   |
// 59|                                                                                                                                                                                                                                                                  |
// 60|                          #                               #                               #                               #                               #                               #                               #                               #       |
// 61|                                                                                                                                                                                                                                                                  |
// 62|                              #                       #                                       #                       #                                       #                       #                                       #                       #           |
// 63|                                                                                                                                                                                                                                                                  |
const uint8_t PROGMEM images_pda_png[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x81, 0xC0, 0xC1, 0xC0, 0x84, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x1F, 0x7F, 0x7F, 0xFE, 0xFC, 0xFC, 0xF0,
  0xE1, 0xC0, 0x81, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x01, 0xC3, 0xC7,
  0xCF, 0xDF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0xC0, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0xC0, 0xC0,
  0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0x7F, 0x3F, 0x1F,
  0x0F, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFE, 0xFC, 0xF8, 0xF0,
  0xE0, 0xC0, 0xF8, 0xFC, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0xC0, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0x7F, 0x3F, 0x1F,
  0x0F, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFE, 0xFC, 0xF8, 0xF0,
  0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0x7F, 0x3F, 0x1F,
  0x0F, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFE, 0xFC, 0xF8, 0xF0,
  0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x84, 0xC0,
  0xE1, 0xF0, 0xF9, 0xFC, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x1F, 0x3F, 0x7F, 0xFE, 0xFC, 0xF8, 0xF0,
  0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0x7F, 0x3F, 0x1F,
  0x0F, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFE, 0xFC, 0xF8, 0xF0,
  0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0x7F, 0x3F, 0x1F,
  0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7C, 0x39, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x81, 0xC0, 0xE1, 0xF0, 0xFC, 0xFC, 0xFE, 0x7F, 0x7F, 0x1F,
  0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x01, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x32, 0x2A,
  0x24, 0x00, 0x1C, 0x22, 0x1C, 0x00, 0x02, 0x3E, 0x00, 0x02, 0x3A, 0x06, 0x00, 0x01, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x43, 0x01, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
};
