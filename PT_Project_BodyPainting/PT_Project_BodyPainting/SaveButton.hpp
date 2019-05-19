#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.h"
using namespace sf;

class SaveButton :public Button {
public:
	sf::Window * window;
	SaveButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale, sf::Window * window) :Button(normal, clicked, hovered, location, scale)
	{
		this->window = window;
	}

	void action() override {
		sf::Texture texture, background;
		texture.create(window->getSize().x, window->getSize().y);
		texture.update(*window);

		std::string filename = "screen.png";

		if (texture.copyToImage().saveToFile(filename))
		{
			background.loadFromFile(filename, sf::IntRect(0, 75, window->getSize().x, window->getSize().y-75));
			background.copyToImage().saveToFile(filename);
		} else
		{
			std::cout << "save failed " << std::endl;
		}

		this->setState(state::state_normal);
	};

	sf::Color getColor() override
	{
		return sf::Color::Black;
	}
};