Arduboy hax
===========

Messing around with programming Arduboy hardware using plain `avr-gcc`
`avrdude` etc, and without the Arduino IDE and Arduboy libraries.

I/O map
-------

| Arduboy | Arduino | AVR |
|---------|---------|-----|
| LEFT    |      A2 | PF5 |
| RIGHT   |      A1 | PF6 |
| UP      |      A0 | PF7 |
| DOWN    |      A3 | PF4 |
| A       |       7 | PE6 |
| B       |       8 | PB4 |
|         |         |     |
| RED     |      10 | PB6 |
| GREEN   |      11 | PB7 |
| BLUE    |       9 | PB5 |
|         |         |     |
| SPKR1   |       5 | PC6 |
| SPKR2   |      13 | PC7 |
