#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.h"
using namespace sf;

class MinusButton :public Button {
public:
	int *size;
	MinusButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale, int *size) :Button(normal, clicked, hovered, location, scale) 
	{
		this->size = size;
	}

	void action() override {
		std::cout << "Minus!";

		//do something

		this->setState(state::state_hovered);
		if (*size > 0)
		{
			(*size)--;
		}
	}

	sf::Color getColor() override
	{
		return sf::Color::Black;
	}
};