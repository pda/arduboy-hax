#pragma once
#if __AVR__
#include <avr/pgmspace.h>
#endif
//  0|                                                                                                                                                                                                                                                                  |
//  1|                                                                                                                                                                                                                                                                  |
//  2|                                                                                                                                                                                                                                                                  |
//  3|                                                                                                                                                                                                                                                                  |
//  4|                                                                                                                                                                                                                                                                  |
//  5|                                                                                                                                                                                                                                                                  |
//  6|                                                                                                                              #                                                                                                                                   |
//  7|                                                                                                                            # # #                                                                                                                                 |
//  8|                                                                                                                            # # #                                                                                                                                 |
//  9|                                                                                                                              # # #                                                                                                                               |
// 10|                                                                                                                                # # #                                                                                                                             |
// 11|                                                                                                                                # # #                                                                                                                             |
// 12|                                                                                                                                  # # #                                                                                                                           |
// 13|                                                                                                                                  # # #                                                                                                                           |
// 14|                                                                                                                                    # # #                                                                                                                         |
// 15|                                                                                                                                      # # #                                                                                                                       |
// 16|                                                                                                                                      # # #                                                                                                                       |
// 17|                                                                                                                                        # # #                                                                                                                     |
// 18|                                                                                                                    # # # # # # # # # # # # #                                                                                                                     |
// 19|                                                                                                                  # # # # # # # # # # # # # # #                                                                                                                   |
// 20|                                                                                                                # # # # # # # # # # # # # # # # #                                                                                                                 |
// 21|                                                                                                                # # #                       # # #                                                                                                                 |
// 22|                                                                                                              # # #                           # # #                                                                                                               |
// 23|                                                                                                              # # #                           # # #                                                                                                               |
// 24|                                                                                                            # # #                               # # #                                                                                                             |
// 25|                                                                                                          # # #                                   # # #                     #                                                                                     |
// 26|                                                                                                          # # #                                   # # #                   # # #                                                                                   |
// 27|                                                                                                        # # #                                       # # #                   # # #                                                                                 |
// 28|                                                                                # # # # # # # # # # # # # # #                                       # # # # # # # # # # # # # # #                                                                                 |
// 29|                                                                              # # # # # # # # # # # # # # #                                           # # # # # # # # # # # # # # #                                                                               |
// 30|                                                                            # # # # # # # # # # # # # # # # #                                       # # # # # # # # # # # # # # # # #                                                                             |
// 31|                                                                            # # #                       # # #                                       # # #                       # # #                                                                             |
// 32|                                                                          # # #                           # # #                                   # # #                           # # #                                                                           |
// 33|                                                                          # # #                           # # #                                   # # #                           # # #                                                                           |
// 34|                                                                        # # #                               # # #                               # # #                               # # #                                                                         |
// 35|                                                                      # # #                                   # # #                           # # #                                   # # #                                                                       |
// 36|                                                                      # # #                                   # # #                           # # #                                   # # #                                                                       |
// 37|                                                                    # # #                                       # # #                       # # #                                       # # #                                                                     |
// 38|                                                                    # # #                                       # # # # # # # # # # # # # # # # #                                       # # #                                                                     |
// 39|                                                                  # # #                                           # # # # # # # # # # # # # # #                                           # # #                                                                   |
// 40|                                                                # # # # #                                       # # # # # # # # # # # # # # # # #                                       # # # # #                                                                 |
// 41|                                                                # # # # #                                       # # #                       # # #                                       # # # # #                                                                 |
// 42|                                                              # # #   # # #                                   # # #                           # # #                                   # # #   # # #                                                               |
// 43|                                                              # # #   # # #                                   # # #                           # # #                                   # # #     #                                                                 |
// 44|                                                            # # #       # # #                               # # #                               # # #                               # # #                                                                         |
// 45|                                                          # # #           # # #                           # # #                                   # # #                           # # #                                                                           |
// 46|                                                          # # #           # # #                           # # #                                   # # #                           # # #                                                                           |
// 47|                                                        # # #               # # #                       # # #                                       # # #                       # # #                                                                             |
// 48|                                                        # # #               # # # # # # # # # # # # # # # # #                                       # # # # # # # # # # # # # # # # #                                                                             |
// 49|                                                      # # #                   # # # # # # # # # # # # # # #                                           # # # # # # # # # # # # # # #                                                                               |
// 50|                                                      # #                       # # # # # # # # # # # # #                                               # # # # # # # # # # # # #                                                                                 |
// 51|                                                    # # #                                                                                                                                                                                                         |
// 52|                                                      #                                                                                                                                                                                                           |
// 53|                                                                                                                                                                                                                                                                  |
// 54|                                                                                                                                                                                                                                                                  |
// 55|                                                                                                                                                                                                                                                                  |
// 56|                                                                                                                                                                                                                                                                  |
// 57|                                                                                                                                                                                                                                                                  |
// 58|                                                                                                                                                                                                                                                                  |
// 59|                                                                                                                                                                                                                                                                  |
// 60|                                                                                                                                                                                                                                                                  |
// 61|                                                                                                                                                                                                                                                                  |
// 62|                                                                                                                                                                                                                                                                  |
// 63|                                                                                                                                                                                                                                                                  |
const uint8_t PROGMEM images_pda2_png[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0F,
  0x3E, 0x7C, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0xF8, 0x3C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
  0x1C, 0x1C, 0x1D, 0x1F, 0x1F, 0x3E, 0xF8, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70,
  0x70, 0x70, 0x70, 0xF8, 0xFE, 0xDF, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0xDF, 0xFE, 0xF8, 0x70, 0x70, 0x70, 0x70,
  0x70, 0x70, 0x70, 0x70, 0x74, 0x7E, 0x7C, 0xF8, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xE0, 0xF8, 0x7C, 0x1F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1F, 0x7C, 0xF8, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
  0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF8, 0x7C, 0x1F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1F, 0x7C, 0xF8, 0xE0, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0x7C, 0x1F,
  0x0F, 0x03, 0x0F, 0x1F, 0x7C, 0xF0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0x7C, 0x1F, 0x0F, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x0F, 0x1F, 0x7C, 0xF0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0x7C, 0x1F, 0x0F, 0x03, 0x07, 0x0F,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1E, 0x0F, 0x03, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
