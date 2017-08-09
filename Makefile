.PHONY: watch
watch: on-create
	./on-create /dev/arduboy avrdude -p m32u4 -c avr109 -P /dev/arduboy -b 57600

on-create: on-create.c
	clang $< -o $@
