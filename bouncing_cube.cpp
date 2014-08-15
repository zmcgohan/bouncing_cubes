#include <iostream>

#include <SFML/Graphics.hpp>

#include "BouncingCubeWindow.h"

const int WINDOW_WIDTH = 1250;
const int WINDOW_HEIGHT = 1000;
const int CUBE_WIDTH = 2;
const int CUBE_SPEED = 500;

int main() {
	BouncingCubeWindow control(WINDOW_WIDTH, WINDOW_HEIGHT, "Bouncing Cubes!", CUBE_WIDTH, CUBE_SPEED);
	control.run();

	return 0;
}
