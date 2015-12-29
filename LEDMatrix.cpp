/**
 * Raspberry Pi 8x8 LED Matrix controller
 *
 * This file is part of LEDMatrix
 *
 * (c) 2015 David Ponevac (david at davidus dot sk) www.davidus.sk
 *
 * https://github.com/davidus-sk/LEDMatrix
 *
 * You are free to use, modify, extend, do whatever you like.
 * Please add attribution to your code.
 */
 
#include "LEDMatrix.h"

using namespace std;

// constructor

/**
 * Constructor
 * @param int data_in_pin GPIO pin number
 * @param int load_pin GPIO pin number
 * @param int clock_pin GPIO pin number
 * @param int device_count Number of device you wish to control
 */
LEDMatrix::LEDMatrix(int data_in_pin, int load_pin, int clock_pin, int devices)
{
	// init globals
	device_count = devices;
	dip = data_in_pin;
	ldp = load_pin;
	clp = clock_pin;

	// configure bit banging pins for output
	rpiGpio.setPinDir(dip, mmapGpio::OUTPUT);
	rpiGpio.setPinDir(ldp, mmapGpio::OUTPUT);
	rpiGpio.setPinDir(clp, mmapGpio::OUTPUT);

	// init the display(s)
	for (int i = 0; i < device_count; i++) {
		write(i, OP_DISPLAYTEST, 0);
		write(i, OP_SCANLIMIT, 7);
		write(i, OP_DECODEMODE, 0);
		clearDisplay(i);
		shutdownDisplay(i, false);
	}
}

// destructor

LEDMatrix::~LEDMatrix()
{

}

// private methods

void LEDMatrix::sendByte(char byte)
{
	for (int i = 0; i < 8; i++) {
		bool bit = leftShift(byte);

		// clock high
		rpiGpio.writePinLow(clp);

		// send bit
		if (bit) {
			rpiGpio.writePinHigh(dip);
		} else {
			rpiGpio.writePinLow(dip);
		}

		// clock low
		rpiGpio.writePinHigh(clp);
	}
}
		
void LEDMatrix::sendPacket(char packet[2])
{
	rpiGpio.writePinHigh(ldp);
	sendByte(packet[0]);
	sendByte(packet[1]);
	rpiGpio.writePinLow(ldp);
	rpiGpio.writePinHigh(ldp);
}
		
void LEDMatrix::write(int device_number, char opcode, char data)
{
	int offset = device_number * 2;
	int bytes = device_count * 2;

	char serial_data[64] = {};

	serial_data[offset] = opcode;
	serial_data[offset+1] = data;

	// send MSB first
	for (int i = 0; i < bytes; i = i + 2) {
		char packet[2] = {serial_data[i], serial_data[i+1]};
		sendPacket(packet);
	}
}

		
template <typename T> bool LEDMatrix::leftShift(T& val)
{
	T const original = val;
	return ((val <<= 1) >> 1) != original;
}

// public methods

/**
 * Shutdown or turn on device
 * @param int deviceNumber
 * @param bool mode
 * @return void
 */
void LEDMatrix::shutdownDisplay(int device_number, bool mode)
{
	if (device_number < 0 || device_number >= device_count) {
		return;
	}

	if (mode) {
		write(device_number, OP_SHUTDOWN,0);
	} else {
		write(device_number, OP_SHUTDOWN,1);
	}
}

/**
 * Clear device
 * @param int deviceNumber
 * @return void
 */
void LEDMatrix::clearDisplay(int device_number)
{
	int offset;

	if (device_number < 0 || device_number >= device_count) {
		return;
	}

    offset = device_number * 8;

    for (int i = 0; i < 8; i++) {
        status[offset+i] = 0;
        write(device_number, i+1, status[offset+i]);
    }
}

/**
 * Set LED panel intensity
 * @param int deviceNumber
 * @param int intensity 0-15
 * @return void
 */
void LEDMatrix::setIntensity(int device_number, int intensity)
{
	if (device_number < 0 || device_number >= device_count) {
		return;
	}

	if (intensity >= 0 && intensity < 16) {	
		write(device_number, OP_INTENSITY, intensity);
	}
}

/**
 * Turn single LED on at row and column
 * @param int deviceNumber
 * @param int row
 * @param int column
 * @param bool state
 * @return void
 */
void LEDMatrix::putLed(int device_number, int row, int column, bool state)
{
	int offset;
	char val = 0x00;

	if (device_number < 0 || device_number >= device_count) {
        return;
	}

	if (row < 0 || row > 7 || column < 0 || column > 7) {
		return;
	}

	offset = device_number * 8;
	val = 0x80 >> column;

	if(state) {
		status[offset+row] = status[offset+row] | val;
	} else {
		val =~ val;
		status[offset+row] = status[offset+row] & val;
	}

	write(device_number, row+1, status[offset+row]);
}

/**
 * Fill row with pattern
 * @param int deviceNumber
 * @param int row
 * @param char value
 * @return void
 */
void LEDMatrix::putRow(int device_number, int row, char value)
{
	int offset;

	if (device_number < 0 || device_number >= device_count) {
		return;
	}

	if (row  < 0 || row > 7) {
		return;
	}

	offset = device_number * 8;
	status[offset+row] = value;
	write(device_number, row+1, status[offset+row]);
}

/**
 * Fill column with pattern
 * @param int deviceNumber
 * @param int column
 * @param char value
 * @return void
 */
void LEDMatrix::putColumn(int device_number, int column, char value)
{
	char val;

	if (device_number < 0 || device_number >= device_count) {
		return;
	}

	if (column < 0 || column > 7) {
		return;
	}

	for (int row = 0; row < 8; row++) {
		val = value >> (7-row);
		val = val & 0x01;
		putLed(device_number, row, column, val);
	}
}

/**
 * Display character
 * @param int deviceNumber
 * @param char character
 * @param const char font
 * @return void
 */
void LEDMatrix::putCharacter(int device_number, char character, const char font[][8])
{
	for (int i = 0; i < 8; i++) {
		putRow(device_number, i, font[character][i]);
	}
}

/**
 * Scroll single character on display
 * @param int deviceNumber
 * @param char character
 * @param const char font
 * @param int speed
 * @return void
 */
void LEDMatrix::scrollCharacter(int device_number, char character, const char font[][8], int speed)
{
	// slice position - 0 to 16
	for (int i = 0; i < 16; i++) {
		int k = i;

		// put on display
		for (int j = 0; j <= i; j++) {

			if (j < 8) {
				putRow(device_number, 7-k, font[character][j]);
			} else {
				putRow(device_number, 7-k, 0);
			}

			k--;	
		}

		usleep(speed);
	}
}

/**
 * Scroll text on display
 * @param int deviceNumber
 * @param string text
 * @param const char font
 * @param int speed
 * @return void
 */
void LEDMatrix::scrollText(int device_number, string text, const char font[][8], int speed)
{
	for (int i = 0; i < text.length(); i++) {
		scrollCharacter(device_number, text.at(i), font, speed);
	}
}