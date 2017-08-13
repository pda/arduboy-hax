#pragma once
#include <avr/io.h>

// Arduboy display: SSD1306 128x64 1-bit OLED, SPI
// CLK:  PB1
// MOSI: PB2
// MISO: PB3
// RST:  PD7
// DC:   PD4
// CS:   PD6

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64

#define SSD1306_PAGES 8
#define SSD1306_PAGE_MAX 7
#define SSD1306_COLS 128
#define SSD1306_COL_MAX 127

// SSD1306 command constants
#define SSD1306_SETLOWCOLUMN        0x00
#define SSD1306_EXTERNALVCC         0x01
#define SSD1306_SWITCHCAPVCC        0x02
#define SSD1306_SETHIGHCOLUMN       0x10
#define SSD1306_MEMORYMODE          0x20
#define SSD1306_SETCOLUMNADDR       0x21
#define SSD1306_SETPAGEADDR         0x22
#define SSD1306_CONTSCROLLH         0x26
#define SSD1306_CONTSCROLLVH        0x28
#define SSD1306_DEACTIVATESCROLL    0x2E
#define SSD1306_ACTIVATESCROLL      0x2F
#define SSD1306_SETSTARTLINE        0x40
#define SSD1306_SETCONTRAST         0x81
#define SSD1306_CHARGEPUMP          0x8D
#define SSD1306_SEGMENTREMAP        0xA0
#define SSD1306_SEGREMAP            0xA0
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON        0xA5
#define SSD1306_NORMALDISPLAY       0xA6
#define SSD1306_INVERTDISPLAY       0xA7
#define SSD1306_SETMULTIPLEX        0xA8
#define SSD1306_DISPLAYOFF          0xAE
#define SSD1306_DISPLAYON           0xAF
#define SSD1306_COMSCANINC          0xC0
#define SSD1306_COMSCANDEC          0xC8
#define SSD1306_SETDISPLAYOFFSET    0xD3
#define SSD1306_SETDISPLAYCLOCKDIV  0xD5
#define SSD1306_SETPRECHARGE        0xD9
#define SSD1306_SETCOMPINS          0xDA
#define SSD1306_SETVCOMDETECT       0xDB


void display_init();
void display_draw_buffer();
void display_image(const uint8_t *);
void display_px(uint8_t x, uint8_t y, uint8_t on);
void display_select_cmd();
void display_select_data();
void display_deselect();
void display_set_dirty();
void display_scroll_start();
void display_scroll_stop();
void display_test_things();
