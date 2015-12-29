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
 
template <typename T, size_t frames, size_t rows> void LEDMatrix::playAnimation(int device_number, const T (&animation)[frames][rows], int iterations, int speed)
{
	for (int i = 0; i < iterations; i++) {
		for (int j = 0; j < frames; j++) {
			for (int k = 0; k < rows; k++) {
				putRow(device_number, k, animation[j][k]);
			}

			usleep(speed);
			clearDisplay(device_number);
		}
	}
}