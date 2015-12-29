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

### Shutdown or turn on display module

```C++
void shutdownDisplay(int device_number, bool mode)
```

* `int device_number` Address of device to turn on/off (zero based)
* `bool mode` true - off; false - on

**Example**

```C++
led->shutdownDisplay(0, true);
```

`void clearDisplay(int device_number)`

`void setIntensity(int device_number, int intensity)`
		
`void putLed(int device_number, int row, int column, bool state)`

`void putRow(int device_number, int row, char value)`

`void putColumn(int device_number, int column, char value)`

`void putCharacter(int device_number, char character, const char font[][8] = CP437_FONT)`

`void scrollCharacter(int device_number, char character, const char font[][8] = CP437_FONT, int speed = 50000)`

`void scrollText(int device_number, string text, const char font[][8] = CP437_FONT, int speed = 50000)`

`template <typename T, size_t frames, size_t rows> void playAnimation(int device_number, const T (&animation)[frames][rows], int iterations = 1, int speed = 50000)`
