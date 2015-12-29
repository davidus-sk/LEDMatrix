# LED Matrix: 8x8 LED Matrix controller (MAX72xx)

This is a simple C++ class which will enable you to connect 8x8 LED matrix(ces) using MAX7219/7221 to your Raspberry Pi (or any other Linux-based device) to display scrolling text, icons and simple animation. It does not rely on SPI, it uses good ole bitbanging to get the job done.

## How to use

Here's a simple demo program you can try. Create a new file _demo.cpp_ and paste this code into it.

```C++
#include "LEDMatrix.h"

int main(void) {
	LEDMatrix * led = new LEDMatrix(17, 23, 22, 1);
	led->putCharacter(0, 'A');
	delete led;
	
	return 0;
}
```

This simple demo creates a new instance of the LEDMatrix object using `LEDMatrix * led = new LEDMatrix(data_pin, load_pin, clock_pin, number_of_displays)` where _data_pin_ is GPIO pin you connected to DIN, _load_pin_ is GPIO pin you connected to LOAD/CS and _clock_pin_ is GPIO pin you connected to CLK on the MAX 72xx chip. Parameter _number_of_displays_ tells the controller how many displays you have connected together; you can chain multiple together if you wish.

Compile your program using `g++ -O3 -std=c++0x -o demo demo.cpp LEDMatrix.cpp mmapGpio.cpp` and then run it `sudo ./demo`. If all goes well and your display is correctly connected to your Pi, you should see letter 'A' appear on the LCD.

A more elaborate demo is found in file _test.cpp_. You compile it in the same manner `g++ -O3 -std=c++0x -o test test.cpp LEDMatrix.cpp mmapGpio.cpp` and then run it `sudo ./demo`.

## Public methods

`LEDMatrix(int data_in_pin, int load_pin, int clock_pin, int device_count)`



`void shutdownDisplay(int device_number, bool mode)`

`void clearDisplay(int device_number)`

`void setIntensity(int device_number, int intensity)`
		
`void putLed(int device_number, int row, int column, bool state)`

`void putRow(int device_number, int row, char value)`

`void putColumn(int device_number, int column, char value)`

`void putCharacter(int device_number, char character, const char font[][8] = CP437_FONT)`

`void scrollCharacter(int device_number, char character, const char font[][8] = CP437_FONT, int speed = 50000)`
		
`void scrollText(int device_number, string text, const char font[][8] = CP437_FONT, int speed = 50000)`
		
`template <typename T, size_t frames, size_t rows> void playAnimation(int device_number, const T (&animation)[frames][rows], int iterations = 1, int speed = 50000)`
