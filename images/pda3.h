#pragma once
#if __AVR__
#include <avr/pgmspace.h>
#endif
//  0|            #   #               # # #       #   #                           #   #                           #   #                         # # # # #                       # # # # #                       # # # # #                       # # # # #               |
//  1|        #           #             # # # #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #             |
//  2|                                    # # #                                                                                             #               #               #               #               #               #               #               #           |
//  3|    #                   #           # # # #             #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #         |
//  4|                            #   #       # # #               #   #                           #   #                         # # # # #                       # # # # #                       # # # # #                       # # # # #                       # #   # |
//  5|    #                   #           #     # # #         #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #         |
//  6|                                            # # #                                                                     #               #               #               #               #               #               #               #               #           |
//  7|        #           #                   # # # # # # #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #             |
//  8|            #   #                     # # # # # # # #                       #   #                         # # # # #                       # # # # #                       # # # # #                       # # # # #                       # # # # #               |
//  9|        #           #               # # #         # # #     # #         #           #                   #           #                   #           #                   #           #                   #           #                   #           #             |
// 10|                                  # # #             # # #   # # #                                     #               #               #               #               #               #               #               #               #               #           |
// 11|    #                   # # # # # # #                 # # # # # # #                     #           #                   #           #                   #           #                   #           #                   #           #                   #         |
// 12|                      # # # # # # # #                 # # # # # # # #                       #   # #                       # # # # #                       # # # # #                       # # # # #                       # # # # #                         #   # |
// 13|    #               # # #         # # #             # # #         # # #                 #           #                   #           #                   #           #                   #           #                   #           #                   #         |
// 14|                  # # #             # # #         # # #             # # #                             #               #               #               #               #               #               #               #               #               #           |
// 15|        #       # # #                 # # # # # # # #                 # # #         #                   #           #                   #           #                   #           #                   #           #                   #           #             |
// 16|            # # # # #                 # # # # # # # #                 # # # #   #                         # # # # #                       # # # # #                       # # # # #                       # # # # #                       # # # # #               |
// 17|        #   # # # # # #             # # #         # # #             # # # # #       #                   #           #                   #           #                   #           #                   #           #                   #           #             |
// 18|          # # #     # # #         # # #             # # #         # # #                               #               #               #               #               #               #               #               #               #               #           |
// 19|    #   # # #         # # # # # # # #                 # # # # # # # #                   #           #                   #           #                   #           #                   #           #                   #           #                   #         |
// 20|      # # #             # # # # # #                     # # # # # #                         #   # #                       # # # # #                         #   # #                         #   # #                       # # # # #                         #   # |
// 21|    # # #               #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #         |
// 22|  # # #                                                                                               #               #               #               #               #               #               #               #               #               #           |
// 23|  # #   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #           # |
// 24|  #         #   #                           #   #                           #   #                         # # # # #                         #   #                           #   #                           #   # #                         #   #               # |
// 25|        #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #             |
// 26|                                                                                                      #               #               #                                                                               #               #                           |
// 27|    #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #         |
// 28|                            #   #                           #   #                         # # # # #                       # # # # #                         #   #                           #   #                         # # # # #                         #   # |
// 29|    #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #         |
// 30|                                                                                      #               #               #               #                                                                               #               #                           |
// 31|        #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #             |
// 32|            #   #                         # # # # #                       # # # # #                       # # # # #                         #   #               # # #       #   #                           #   # #                       # # # # #               |
// 33|        #           #                   #           #                   #           #                   #           #                   #           #             # # # #           #                   #           #                   #           #             |
// 34|                                      #               #               #               #               #               #               #                             # # #                                             #               #               #           |
// 35|    #                   #           #                   #           #                   #           #                   #           #                   #           # # # #             #           #                   #           #                   #         |
// 36|                          # # # # #                         #   # #                       # # # # #                       # # # # #                         #   #       # # #               #   #                           #   # #                       # # # # |
// 37|    #                   #           #                   #           #                   #           #                   #           #                   #           #     # # #         #           #                   #           #                   #         |
// 38|                      #               #               #               #               #               #               #               #                                     # # #                                                     #               #           |
// 39|        #           #                   #           #                   #           #                   #           #                   #           #                   # # # # # # #                   #           #                   #           #             |
// 40|          # # # # #                       # # # # #                       # # # # #                       # # # # #                         #   #                     # # # # # # # #                       #   #                         # # # # #               |
// 41|        #           #                   #           #                   #           #                   #           #                   #           #               # # #         # # #     # #         #           #                   #           #             |
// 42|      #               #               #               #               #               #               #               #               #                           # # #             # # #   # # #                                     #               #           |
// 43|    #                   #           #                   #           #                   #           #                   #           #                   # # # # # # #                 # # # # # # # #                   #           #                   #         |
// 44|  #                       # # # # #                       # # # # #                         #   # #                         #   #                     # # # # # # # #                 # # # # # # # #                       #   # #                       # # # # |
// 45|    #                   #           #                   #           #                   #           #                   #           #               # # #         # # #             # # #         # # #                 #           #                   #         |
// 46|      #               #               #               #               #               #               #               #                           # # #             # # #         # # #             # # #                             #               #           |
// 47|        #           #                   #   #   #   #                   #           #                   #           #                   #       # # #                 # # # # # # # #                 # # #         #                   #           #             |
// 48|          # # # # #                       # # # # #                         #   #                           #   #                           # # # # #                 # # # # # # # #                 # # # #   #                         # # # # #               |
// 49|        #           #                   #           #                   #           #                   #           #                   #   # # # # # #             # # #         # # #             # # # # #       #                   #           #             |
// 50|      #               #               #               #               #                                                                   # # #     # # #         # # #             # # #         # # #                               #               #           |
// 51|    #                   #           #                   #           #                   #           #                   #           #   # # #         # # # # # # # #                 # # # # # # # #                   #           #                   #         |
// 52|  #                       # # # # #                       # # # # #                       # # # # #                         #   #     # # #             # # # # # #                     # # # # # #                         #   # #                       # # # # |
// 53|    #                   #           #                   #           #                   #           #                   #           # # #               #           #                   #           #                   #           #                   #         |
// 54|      #               #               #               #               #               #               #                           # # #                                                                                               #               #           |
// 55|        #           #                   #           #                   #           #                   #           #             # #   #           #                   #           #                   #           #                   #           #             |
// 56|          # # # # #                       # # # # #                       # # # # #                         #   #                           #   #                           #   #                           #   #                           #   # #               |
// 57|        #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #             |
// 58|      #               #               #               #               #               #               #                                                                                                                                               #           |
// 59|    #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #         |
// 60|  #                         #   # #                         #   # #                         #   #                           #   #                           #   #                           #   #                           #   #                           #   # |
// 61|    #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #         |
// 62|      #               #               #               #               #               #                                                                                                                                                                           |
// 63|        #           #           # #     #           #                   #           #                   #           #                   #           #                   #           #                   #           #                   #           #             |
const uint8_t PROGMEM images_pda3_png[] = {
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x11,
  0x03, 0x2F, 0x0E, 0x9E, 0xB8, 0xF1, 0xE0, 0xC1, 0x80, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x40, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x81, 0xC0, 0xE2, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18,
  0x3C, 0x7E, 0xE7, 0xC3, 0x81, 0x81, 0x81, 0x81, 0xC3, 0xE7, 0x7E, 0x3C, 0x18, 0x1E, 0x1E, 0x1C,
  0x38, 0x70, 0xE0, 0xC2, 0x80, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x10,
  0xC0, 0xE8, 0x70, 0xBA, 0x1C, 0x0F, 0x07, 0x03, 0x03, 0x87, 0x0E, 0x3C, 0x18, 0x18, 0x18, 0x18,
  0x1C, 0x2E, 0x07, 0x83, 0x01, 0x01, 0x01, 0x01, 0x03, 0x87, 0x0E, 0x3C, 0x18, 0x18, 0x18, 0x18,
  0x1C, 0x2E, 0x07, 0x83, 0x03, 0x03, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x90,
  0x01, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x40, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x11,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x40, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x11,
  0x03, 0x2F, 0x0E, 0x9E, 0xB8, 0xF1, 0xE0, 0xC1, 0x80, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x01, 0x82, 0x04, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x81, 0x01, 0x81, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x04, 0x82, 0x00, 0x01, 0x00, 0x81, 0xC0, 0xE2, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18,
  0x3C, 0x7E, 0xE7, 0xC3, 0x81, 0x81, 0x81, 0x81, 0xC3, 0xE7, 0x7E, 0x3C, 0x18, 0x1E, 0x1E, 0x1C,
  0x38, 0x78, 0xE0, 0xC2, 0x80, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x40, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x40, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0xC0, 0xE8, 0x70, 0xBA, 0x1C, 0x0F, 0x07, 0x03, 0x03, 0x87, 0x0E, 0x3C, 0x18, 0x18, 0x18, 0x18,
  0x1C, 0x2E, 0x07, 0x83, 0x01, 0x01, 0x01, 0x01, 0x03, 0x87, 0x0E, 0x3C, 0x18, 0x18, 0x18, 0x18,
  0x1C, 0x2E, 0x07, 0x83, 0x03, 0x03, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x90,
  0x90, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x10, 0x28, 0x44, 0x82, 0x01, 0x01, 0x01, 0x01, 0x01, 0x82, 0x44, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x04, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x00, 0x82, 0x00, 0x28, 0x00, 0x10, 0x00, 0x10,
  0x00, 0x28, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x01, 0x82, 0x04, 0x28, 0x00, 0x10, 0x00, 0x10,
};
