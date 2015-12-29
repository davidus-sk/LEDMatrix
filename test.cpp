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

int main(void) {
	LEDMatrix * led = new LEDMatrix(17, 23, 22, 4);

	led->putCharacter(0, 0, ICON_FONT);
	
	return 0;

	for (int i = 0; i < 256; i++) {
		led->putCharacter(0, i);
		usleep (300000);
	}
	
	while (true) {
		led->playAnimation(0, FULL_SQUARE_ANIMATION, 20, 90000);
		led->playAnimation(0, EMPTY_SQUARE_ANIMATION, 20, 90000);
		led->playAnimation(0, EMPTY_CIRCLE_ANIMATION, 20, 90000);
		led->playAnimation(0, SPINNER_ANIMATION, 10);
		led->playAnimation(0, INVADER_ANIMATION, 20, 90000);
		led->playAnimation(0, ROBOT_ANIMATION, 20, 90000);
		led->playAnimation(0, EMO_FACE_ANIMATION, 20, 90000);
		led->playAnimation(0, TALKING_FACE_ANIMATION, 20, 90000);
		led->playAnimation(0, ARROW_ANIMATION, 10);
		led->playAnimation(0, CHECKERS_ANIMATION, 20,90000);
		led->playAnimation(0, HOURGLASS_ANIMATION, 20,90000);
		led->playAnimation(0, CHECK_ANIMATION, 20,90000);
		led->playAnimation(0, TRANSMIT_ANIMATION, 20, 90000);
	}

	return 0;
}