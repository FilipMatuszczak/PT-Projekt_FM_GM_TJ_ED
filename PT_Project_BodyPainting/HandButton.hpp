#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.h"
using namespace sf;

class HandButton : public Button {
public:
	bool *capture;
	HandButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale, bool *capture) :Button(normal, clicked, hovered, location, scale) {
		this->capture = capture;
	}

	void action() override {
		if (*capture)
		{
			*capture = false;
		}
		else *capture = true;
	}

	sf::Color getColor() override
	{
		return sf::Color::Black;
	}
};