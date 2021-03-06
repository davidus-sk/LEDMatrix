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
 
#ifndef ANIMATION_H
#define ANIMATION_H

/**
 * Display is gradually filling up from center out
 */
const char FULL_SQUARE_ANIMATION[][8] = {
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x3c,0x3c,0x3c,0x3c,0x00,0x00},
	{0x00,0x7e,0x7e,0x7e,0x7e,0x7e,0x7e,0x00},
	{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
};

/**
 * One pixel wide square gradually growing
 */
const char EMPTY_SQUARE_ANIMATION[][8] = {
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x3c,0x24,0x24,0x3c,0x00,0x00},
	{0x00,0x7e,0x42,0x42,0x42,0x42,0x7e,0x00},
	{0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff},
};

const char EMPTY_CIRCLE_ANIMATION[][8] = {
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x18,0x24,0x24,0x18,0x00,0x00},
	{0x00,0x18,0x24,0x42,0x42,0x24,0x18,0x00},
	{0x3c,0x42,0x81,0x81,0x81,0x81,0x42,0x3c},
	{0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x81},
};

const char SPINNER_ANIMATION[][8] = {
	{0x80,0x40,0x20,0x18,0x18,0x00,0x00,0x00},
	{0x40,0x20,0x10,0x18,0x18,0x00,0x00,0x00},
	{0x10,0x10,0x10,0x18,0x18,0x00,0x00,0x00},
	{0x08,0x08,0x08,0x18,0x18,0x00,0x00,0x00},
	{0x02,0x04,0x08,0x18,0x18,0x00,0x00,0x00},
	{0x01,0x02,0x04,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x01,0x02,0x1c,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x1f,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x1f,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x1c,0x02,0x01,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x04,0x02,0x01},
	{0x00,0x00,0x00,0x18,0x18,0x08,0x04,0x02},
	{0x00,0x00,0x00,0x18,0x18,0x08,0x08,0x08},
	{0x00,0x00,0x00,0x18,0x18,0x10,0x10,0x10},
	{0x00,0x00,0x00,0x18,0x18,0x10,0x20,0x40},
	{0x00,0x00,0x00,0x18,0x18,0x20,0x40,0x80},
	{0x00,0x00,0x00,0x18,0x38,0x40,0x80,0x00},
	{0x00,0x00,0x00,0x18,0xf8,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xf8,0x18,0x00,0x00,0x00},
	{0x00,0x80,0x40,0x38,0x18,0x00,0x00,0x00},
};

const char INVADER_ANIMATION[][8] = {
	{0x38,0x1d,0xf6,0x3c,0x3c,0xf6,0x1d,0x38},
	{0x38,0x9d,0x76,0x3c,0x3c,0x76,0x9d,0x38},
	{0x38,0x1d,0x76,0xbc,0xbc,0x76,0x1d,0x38},
};

const char ROBOT_ANIMATION[][8] = {
	{0x30,0x08,0xfc,0x3f,0x3f,0xfc,0x08,0x30},
	{0x30,0x08,0xfc,0x3f,0x3f,0xfc,0x08,0x08},
	{0x30,0x08,0xfc,0x3f,0x3f,0x7c,0x88,0x06},
	{0x30,0x08,0xfc,0x3f,0x3f,0x7c,0x88,0x08},
	{0x30,0x08,0xfc,0x3f,0x3f,0xfc,0x08,0x30},
	{0x08,0x08,0xfc,0x3f,0x3f,0xfc,0x08,0x30},
	{0x06,0x88,0x7c,0x3f,0x3f,0xfc,0x08,0x30},
	{0x30,0x88,0x7c,0x3f,0x3f,0xfc,0x08,0x30},
};

const char EMO_FACE_ANIMATION[][8] = {
	{0x3c,0x42,0x95,0xa1,0xa1,0x95,0x42,0x3c},
	{0x3c,0x42,0x95,0x91,0x91,0x95,0x42,0x3c},
	{0x3c,0x42,0xa5,0x91,0x91,0xa5,0x42,0x3c},
	{0x3c,0x42,0x95,0x91,0x91,0x95,0x42,0x3c},
};

const char TALKING_FACE_ANIMATION[][8] = {
	{0xff,0xf9,0xb9,0xbf,0xbf,0xb9,0xf9,0xff},
	{0xff,0xf9,0x99,0x9f,0x9f,0x99,0xf9,0xff},
	{0xff,0xf9,0x89,0xaf,0xaf,0x89,0xf9,0xff},
	{0xff,0xf9,0x99,0x9f,0x9f,0x99,0xf9,0xff},
};

const char ARROW_ANIMATION[][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00},
	{0x00,0x00,0x80,0xc0,0xc0,0x80,0x00,0x00},
	{0x00,0x80,0xc0,0xe0,0xe0,0xc0,0x80,0x00},
	{0x80,0xc0,0xe0,0xf0,0xf0,0xe0,0xc0,0x80},
	{0x40,0x60,0xf0,0xf8,0xf8,0xf0,0x60,0x40},
	{0x20,0x30,0xf8,0xfc,0xfc,0xf8,0x30,0x20},
	{0x10,0x18,0xfc,0xfe,0xfe,0xfc,0x18,0x10},
	{0x08,0x0c,0xfe,0xff,0xff,0xfe,0x0c,0x08},
	{0x04,0x06,0xff,0xff,0xff,0xff,0x06,0x04},
	{0x02,0x03,0x7f,0x7f,0x7f,0x7f,0x03,0x02},
	{0x01,0x01,0x3f,0x3f,0x3f,0x3f,0x01,0x01},
	{0x00,0x00,0x1f,0x1f,0x1f,0x1f,0x00,0x00},
	{0x00,0x00,0x0f,0x0f,0x0f,0x0f,0x00,0x00},
	{0x00,0x00,0x07,0x07,0x07,0x07,0x00,0x00},
	{0x00,0x00,0x03,0x03,0x03,0x03,0x00,0x00},
	{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},
};

const char CHECKERS_ANIMATION[][8] = {
	{0xcc,0xcc,0x33,0x33,0xcc,0xcc,0x33,0x33},
	{0x33,0x33,0xcc,0xcc,0x33,0x33,0xcc,0xcc},
};

const char HOURGLASS_ANIMATION[][8] = {
	{0xc3,0xa7,0x9f,0x8f,0x8f,0x9f,0xa7,0xc3},
	{0xc3,0xa7,0x9f,0x8f,0x87,0x9f,0xe7,0xc3},
	{0xc3,0xa7,0x9f,0x87,0x87,0xdf,0xe7,0xc3},
	{0xc3,0xa7,0x9f,0x87,0xc7,0xdb,0xe7,0xc3},
	{0xc3,0xa7,0x9f,0xc7,0xc3,0xdb,0xe7,0xc3},
	{0xc3,0xa7,0xdf,0xc3,0xc3,0xdb,0xe7,0xc3},
	{0xc3,0xe7,0xdb,0xc3,0xc3,0xdb,0xe7,0xc3},
	{0xc3,0xe7,0xdb,0xc3,0xc3,0xfb,0xe5,0xc3},
	{0xc3,0xe7,0xdb,0xc3,0xe3,0xf9,0xe5,0xc3},
	{0xc3,0xe7,0xdb,0xe3,0xe1,0xf9,0xe5,0xc3},
	{0xc3,0xe7,0xfb,0xe1,0xe1,0xf9,0xe5,0xc3},
	{0xc3,0xe7,0xf9,0xe1,0xf1,0xf9,0xe5,0xc3},
	{0xc3,0xe5,0xf9,0xf1,0xf1,0xf9,0xe5,0xc3},
};

const char CHECK_ANIMATION[][8] = {
	{0x00,0x02,0x07,0x2e,0x7c,0x38,0x10,0x00},
	{0xff,0xfd,0xf8,0xd1,0x83,0xc7,0xef,0xff},
};

const char TRANSMIT_ANIMATION[][8] = {
	{0xff,0xff,0x8f,0xf7,0x9b,0xeb,0xab,0xff},
	{0xff,0x8f,0xf7,0x9b,0xed,0xb5,0xd5,0xff},
};
	
#endif