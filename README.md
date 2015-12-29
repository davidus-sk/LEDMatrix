# LED Matrix: 8x8 LED Matrix controller (MAX72xx)

This simple C++ class enables you to connect 8x8 LED matrix(ces) using MAX7219/7221 driver to your Raspberry Pi (or any other Linux-based device) to display scrolling text, various icons and simple animations. This class does not use SPI, rather it uses good ole bitbanging to get the job done.

## How to use

Here is a simple demo program you can start with. Create a new file *demo.cpp* and paste the following code into it.

```C++
#include "LEDMatrix.h"

int main(void) {
	LEDMatrix * led = new LEDMatrix(17, 23, 22, 1);
	led->putCharacter(0, 'A');
	delete led;
	
	return 0;
}
```

This simple demo creates a new instance of the LEDMatrix object using `LEDMatrix * led = new LEDMatrix(data_pin, load_pin, clock_pin, number_of_displays)` where *data_pin* is GPIO pin you connected to DIN, *load_pin* is GPIO pin you connected to LOAD/CS and *clock_pin* is GPIO pin you connected to CLK on the MAX 72xx chip. Parameter *number_of_displays* tells the controller how many display modules are connected together; you can chain multiple together and extend your scrolling/display area.

Compile your demo program using `g++ -O3 -std=c++0x -o demo demo.cpp LEDMatrix.cpp mmapGpio.cpp` and then run it `sudo ./demo`. If all goes well and your display is correctly connected to your Pi you should see letter 'A' appear on the LCD.

For more elaborate examples checkout out *test.cpp*. You compile it in the same manner `g++ -O3 -std=c++0x -o test test.cpp LEDMatrix.cpp mmapGpio.cpp` and then run it `sudo ./test`.

## Public methods

### Constructor

```C++
LEDMatrix(int data_in_pin, int load_pin, int clock_pin, int device_count)
```

* `int data_in_pin` GPIO pin number connected to DIN pin on MAX72xx
* `int load_pin` GPIO pin number connected to LOAD/CS pin on MAX72xx
* `int clk_pin` GPIO pin number connected to CLK pin on MAX72xx
* `int device_count` Number of display modules chained together

**Example**

```C++
LEDMatrix * led = new LEDMatrix(17, 23, 22, 1);
```

### Turn on/off display module

```C++
void shutdownDisplay(int device_number, bool mode)
```

* `int device_number` Address of device to turn on/off (zero based)
* `bool mode` true - off, false - on

**Example**

```C++
led->shutdownDisplay(0, true);
```

### Turn all LED segments off

```C++
void clearDisplay(int device_number)
```

* `int device_number` Device address (zero based)

**Example**

```C++
led->clearDisplay(0);
```

### Set brightness of display module

```C++
void setIntensity(int device_number, int intensity)
```

* `int device_number` Device address (zero based)
* `int intensity` Dimmer (0) to brighter (15)

**Example**

```C++
led->setIntensity(0, 15);
```

### Turn single LED on/off at [row,column]

```C++
void putLed(int device_number, int row, int column, bool state)
```

* `int device_number` Device address (zero based)
* `int row` Row number 0 through 7
* `int column` Column number 0 through 7
* `bool state` LED state: false - off, true - on

**Example**

```C++
led->putLed(0, 1, 1, true);
```

### Display row pattern

```C++
void putRow(int device_number, int row, char value)
````

* `int device_number` Device address (zero based)
* `int row` Row number 0 through 7
* `char value` Bit pattern to show in row from 0x00 (all off) to 0xFF (all on)

**Example**

```C++
led->putRow(0, 1, 0x93);
```

### Display column pattern

```C++
void putColumn(int device_number, int column, char value)
```

* `int device_number` Device address (zero based)
* `int column` Column number 0 through 7
* `char value` Bit pattern to show in column from 0x00 (all off) to 0xFF (all on)

**Example**

```C++
led->putColumn(0, 1, 0x93);
```

### Display character

```C++
void putCharacter(int device_number, char character, const char font[][8] = CP437_FONT)
```

* `int device_number` Device address (zero based)
* `char character` Character to show ASCII/CP437 (0 to 255)
* `const char font[][8]` Specific font to use, see *fonts.h*

**Example**

```C++
led->putCharacter(0, 'A');
```

### Scroll single character

```C++
void scrollCharacter(int device_number, char character, const char font[][8] = CP437_FONT, int speed = 50000)
```

* `int device_number` Device address (zero based)
* `char character` Character to show ASCII/CP437 (0 to 255)
* `const char font[][8]` Specific font to use, see *fonts.h*
* `int speed` Bigger the number, slower the scrolling speed

**Example**

```C++
led->scrollCharacter(0, 'A');
```

### Scroll text

```C++
void scrollText(int device_number, string text, const char font[][8] = CP437_FONT, int speed = 50000)
```

* `int device_number` Device address (zero based)
* `string text` Text to scroll
* `const char font[][8]` Specific font to use, see *fonts.h*
* `int speed` Bigger the number, slower the scrolling speed

**Example**

```C++
led->scrollText(0, 'Text');
```

### Play animation

```C++
template <typename T, size_t frames, size_t rows> void playAnimation(int device_number, const T (&animation)[frames][rows], int iterations = 1, int speed = 50000)
```

* `int device_number` Device address (zero based)
* `const char font[][8]` Animation to use, see *animations.h*
* `int iterations` Number of iterations (plays)
* `int speed` Bigger the number, slower the scrolling speed

**Example**

```C++
led->playAnimation(0, TALKING_FACE_ANIMATION, 20, 90000);
```
