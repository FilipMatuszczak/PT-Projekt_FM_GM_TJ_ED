#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.hpp"
using namespace sf;

class MinusButton :public Button {
public:
	MinusButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale) :Button(normal, clicked, hovered, location, scale) {}

	void action() override {
		std::cout << "Minus!";

		//do something

		this->setState(state::state_hovered);
	}
};