#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.h"
using namespace sf;

class ClearButton : public Button {
public:
	std::vector<std::vector<sf::VertexArray>> *vertices;
	sf::Texture *window;
	ClearButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale, sf::Texture*window) :Button(normal, clicked, hovered, location, scale)
	{
		this->window = window;
	}

	void action() override {

		window->create(window->getSize().x, window->getSize().y);
		window->loadFromFile("./icons/background.png");



		this->setState(state::state_normal);

	}

	sf::Color getColor() override
	{
		return sf::Color::Black;
	}
};