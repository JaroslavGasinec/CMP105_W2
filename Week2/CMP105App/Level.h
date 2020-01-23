#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include <cmath>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	sf::CircleShape circle;
	sf::Text text;
	sf::Text text2;
	sf::Font font;
	sf::Vector2u initialMouse;
	sf::Vector2u finalMouse;
	double distanceMouse = 0.00;
	bool clickHappening = false;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Add your object here

};