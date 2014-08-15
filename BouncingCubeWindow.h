#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>

struct Cube {
	sf::RectangleShape* cube;
	int vel_x, vel_y;
} ;

class BouncingCubeWindow {
public:
	// creates a window
	BouncingCubeWindow(int width, int height, std::string title, int cube_width, int cube_speed);
	// adds a cube to the window
	void add_cube();
	// updates each cube in {@code cubes} positions
	void update_positions();
	// updates the window's look
	void render();
	// updates framerate every 60 frames
	void update_framerate();
	// starts main loop
	void run();
private:
	sf::RenderWindow* window;
	// used to update cube's positions at a consistent speed
	sf::Clock* clock;
	std::vector<Cube*> cubes;
	int cube_width, cube_speed;
} ;
