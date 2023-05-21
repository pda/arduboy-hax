# see default.env for parameters

AVRDUDE_FLAGS = -q -q \
								-p $(ISP_MCU) \
								-c $(ISP_PROGRAMMER) \
								-P $(ISP_PORT)

CC = avr-gcc

LDFLAGS = -Wl,-Map,firmware.map

COMPILEFLAGS = -Wall \
							 -Werror \
							 -g \
							 -Os \
							 -mmcu=$(MCU) \
							 -DF_CPU=$(F_CPU) \
							 -DBAUD=$(BAUD)

# clang doesn't have gcc's __builtin_avr_delay_cycles,
# so force the alternate implementation in avr-gcc/avr/include/util/delay.h
COMPILEFLAGS += -D__DELAY_BACKWARD_COMPATIBLE__=true

# clang doesn't have something something __ATTR_PROGMEM__
COMPILEFLAGS += -D__ATTR_PROGMEM__='__attribute__((section(".progmem1.data")))'

CFLAGS = $(COMPILEFLAGS) \
				 -std=c99

ASFLAGS = $(COMPILEFLAGS)

SOURCES = main.c display.c spi.c led.c game.c
OBJECTS = $(SOURCES:.c=.o)

PNGS = $(wildcard images/*.png)
PNG_OUT = $(PNGS:.png=.h)

.PHONY: all
all: firmware.hex

.PHONY: clean
clean:
	rm -f .depend firmware.elf firmware.hex $(OBJECTS)

.PHONY: burn
burn: firmware.hex
	avrdude $(AVRDUDE_FLAGS) -U $<

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
.PHONY: watch
watch:
	tools/on-create $(ISP_PORT) make burn
else ifeq ($(UNAME_S), Darwin)
.PHONY: watch
watch:
	fswatch --monitor poll_monitor --event-flags --event Created --print0 $(ISP_PORT) | xargs -0 -n 1 -I {} make burn
endif

firmware.hex: firmware.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

firmware.elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

images/%.h: images/%.png tools
	tools/png2c $< >$@

.depend: $(SOURCES) $(PNG_OUT)
	rm -f -- .depend
	$(CC) $(CFLAGS) -MM $^ > .depend;
include .depend
