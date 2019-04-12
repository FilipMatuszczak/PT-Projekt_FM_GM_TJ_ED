#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.hpp"
using namespace sf;

class ClearButton : public Button {
public:
	ClearButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale) :Button(normal, clicked, hovered, location, scale) {}

	void action() override {
		std::cout << "Clear!";
	}
};