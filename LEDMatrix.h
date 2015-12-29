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
 *
 * mmapGpio is taken from http://www.hertaville.com/rpimmapgpio.html
 */

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <time.h>

#include "mmapGpio.h"
#include "fonts.h"
#include "animation.h"

using namespace std;

#ifndef LEDMATRIX_H
#define LEDMATRIX_H

// register addresses
#define OP_NOOP 0x00
#define OP_DIGIT0 0x01
#define OP_DIGIT1 0x02
#define OP_DIGIT2 0x03
#define OP_DIGIT3 0x04
#define OP_DIGIT4 0x05
#define OP_DIGIT5 0x06
#define OP_DIGIT6 0x07
#define OP_DIGIT7 0x08
#define OP_DECODEMODE 0x09
#define OP_INTENSITY 0x0A
#define OP_SCANLIMIT 0x0B
#define OP_SHUTDOWN 0x0C
#define OP_DISPLAYTEST 0x0F

class LEDMatrix
{
	private:
		mmapGpio rpiGpio;
		char status[64];
		int device_count;
		int dip, ldp, clp;

		// send by to device
		void sendByte(char byte);
		
		// send packet (two bytes) to device
		// see: sendByte
		void sendPacket(char packet[2]);
		
		// write command to device
		// see: sendPacket
		void write(int device_number, char opcode, char data);
		
		// left shift byte and return shifted value
		template <typename T> bool leftShift(T& val);

	public:
		// constructor & destructor
		LEDMatrix(int data_in_pin, int load_pin, int clock_pin, int device_count);
		~LEDMatrix();

		// shutdown or turn on display. mode 0: off, 1: on
		void shutdownDisplay(int device_number, bool mode);
		
		// erase display
		void clearDisplay(int device_number);
		
		// set led output intensity
		void setIntensity(int device_number, int intensity);
		
		// turn LED on or off at row/column
		void putLed(int device_number, int row, int column, bool state);
		
		// send pattern to specific row
		void putRow(int device_number, int row, char value);
		
		// send pattern to specific column
		void putColumn(int device_number, int column, char value);
		
		// show specific character on display
		void putCharacter(int device_number, char character, const char font[][8] = CP437_FONT);
		
		// scroll single character on display
		void scrollCharacter(int device_number, char character, const char font[][8] = CP437_FONT, int speed = 50000);
		
		// scroll text on display
		void scrollText(int device_number, string text, const char font[][8] = CP437_FONT, int speed = 50000);
		
		// play animation on display
		template <typename T, size_t frames, size_t rows> void playAnimation(int device_number, const T (&animation)[frames][rows], int iterations = 1, int speed = 50000);
};

#include "LEDMatrix.tpl"

#endif