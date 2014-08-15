#include "BouncingCubeWindow.h"

BouncingCubeWindow::BouncingCubeWindow(int width, int height, std::string title, int cube_width, int cube_speed) : window(new sf::RenderWindow(sf::VideoMode(width, height), title)), cube_width(cube_width), cube_speed(cube_speed) {
	window->setFramerateLimit(60);
	srand(time(NULL));
	for(int i = 0; i < 5000; ++i) {
		add_cube();
	}
}

void BouncingCubeWindow::add_cube() {
	Cube* new_cube = new Cube();

	new_cube->cube = new sf::RectangleShape(sf::Vector2f(cube_width, cube_width));
	new_cube->cube->setFillColor(sf::Color(0,0,0));

	// set velocity components to random
	new_cube->vel_x = rand() % cube_speed;
	new_cube->vel_y = sqrt(cube_speed*cube_speed - new_cube->vel_x*new_cube->vel_x);

	cubes.push_back(new_cube);
}

void BouncingCubeWindow::update_positions() {
	int ms_elapsed = clock->restart().asMilliseconds();

	for(int i = 0; i < cubes.size(); ++i) {
		sf::Vector2f cur_pos = cubes[i]->cube->getPosition();
		double move_x = cubes[i]->vel_x / 1000.0 * ms_elapsed;
		double move_y = cubes[i]->vel_y / 1000.0 * ms_elapsed;
		if(cur_pos.x + move_x < 0 || cur_pos.x + move_x + cube_width > window->getSize().x + 2) {
			move_x = -move_x;
			cubes[i]->vel_x = -cubes[i]->vel_x;
		} 
		if(cur_pos.y + move_y < 0 || cur_pos.y + move_y + cube_width > window->getSize().y + 2) {
			move_y = -move_y;
			cubes[i]->vel_y = -cubes[i]->vel_y;
		} 
		cubes[i]->cube->move(move_x, move_y);
	}
}

void BouncingCubeWindow::update_framerate() {
	static int last_updated = 0;
	static int time_accumulated = 0;
	++last_updated;
	time_accumulated += clock->getElapsedTime().asMilliseconds();
	if(last_updated == 300) {
		double FPS = (300 / (time_accumulated / 1000.0));
		std::cout << "Number of cubes: " << cubes.size() << " :.:.: FPS: " << FPS << std::endl;
		for(int i = 0; i < 1000; ++i) {
			add_cube();
		}
		last_updated = time_accumulated = 0;
	}
}

void BouncingCubeWindow::render() {
	window->clear(sf::Color::White);

	for(int i = 0; i < cubes.size(); ++i) {
		window->draw(*cubes[i]->cube);
	}

	window->display();
}

void BouncingCubeWindow::run() {
	clock = new sf::Clock();

	while(window->isOpen()) {
		sf::Event event;
		while(window->pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window->close();
			} else if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Space)
					add_cube();
			}
		}

		update_positions();
		render();
		update_framerate();
	}
}
