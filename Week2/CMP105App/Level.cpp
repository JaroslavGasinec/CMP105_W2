#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	font.loadFromFile("font/arial.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(50);
	text.setPosition(100, 20);

	text2.setFont(font);
	text2.setFillColor(sf::Color::White);
	text2.setCharacterSize(30);
	text2.setPosition(350, 40);

	circle.setPosition(0,0);
	circle.setRadius(30);
	circle.setFillColor(sf::Color::Red);
	
	// initialise game objects

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	//2a
	if (input->isKeyDown(sf::Keyboard::W)) {
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W is pressed" << std::endl;
	}
	//2b
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L)) {
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "combo is pressed" << std::endl;
	}
	//3
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		window->close();
	}
	//5
	if (input->isMouseLDown() && !clickHappening ) {
		clickHappening = true;
		initialMouse.x = input->getMouseX();
		initialMouse.y = input->getMouseY();
	}
	else if (input->isMouseLDown()) {
		finalMouse.x = input->getMouseX();
		finalMouse.y = input->getMouseY();
	}
	else if (!input->isMouseLDown() && clickHappening) {
		clickHappening = false;
	}
	//6
	if (input->isMouseRDown()) {
		circle.setPosition(input->getMouseX()-30, input->getMouseY()-30);
	}
}

// Update game objects
void Level::update()
{
	//4
	std::string s = std::to_string(input->getMouseX()) + "," + std::to_string(input->getMouseY());
	text.setString(s);
	//5
	sf::Vector2u difference = initialMouse - finalMouse;
	distanceMouse = sqrt((difference.x * difference.x) + (difference.y * difference.y));
	s = "distance: " + std::to_string(distanceMouse);
	text2.setString(s);

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	window->draw(text2);
	window->draw(circle);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 100, 100));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}