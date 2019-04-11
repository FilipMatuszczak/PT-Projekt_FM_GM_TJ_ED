#pragma once

#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"

using namespace sf;

class Button {
public:
	static enum state {state_clicked, state_hovered, state_normal};
	Button(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location);
	void checkHover(sf::Vector2f);
	void checkNormal(sf::Vector2f mousePos);
	void setState(state);
	state getState();
	sf::Sprite* getSprite();
private:
	sf::Sprite normal;
	sf::Sprite clicked;
	sf::Sprite hovered;
	sf::Sprite* currentSpr;
	state current;
};
