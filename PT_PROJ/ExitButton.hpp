#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.hpp"
using namespace sf;

class ExitButton : public Button {
public:
	sf::Window * window;
	ExitButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale, sf::Window * window) :Button(normal, clicked, hovered, location, scale) 
	{
		this -> window = window;
	}

	void action() override {
		this->window->close();
	}
};