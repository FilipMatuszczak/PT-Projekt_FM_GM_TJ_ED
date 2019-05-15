#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.hpp"
using namespace sf;

class PenButton :public Button {
public:
	sf::Color *curr_col;
	std::vector<Button*> *toolButtons;
	std::vector<Button*> *colorButtons;
	PenButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale, sf::Color *curr_col, std::vector<Button*> &toolButtons, std::vector<Button*> &colorButtons) :Button(normal, clicked, hovered, location, scale) {
		this->curr_col = curr_col;
		this->toolButtons = &toolButtons;
		this->colorButtons = &colorButtons;
	}

	void action() override {
		for (Button *b : *toolButtons)
		{
			if (b->isClicked())
			{
				b->setState(state::state_normal);
			}
		}

		for (Button *b : *colorButtons)
		{
			if (b->isClicked())
			{
				*this->curr_col = b->getColor();
			}
		}

		this->setState(state::state_clicked);
	}

	sf::Color getColor() override
	{
		return sf::Color::Black;
	}
};