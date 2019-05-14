#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.hpp"
using namespace sf;

class EraserButton : public Button {
public:
	sf::Color *curr_col;
	std::vector<Button*> *colorButtons;
	EraserButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale, sf::Color *curr_col, std::vector<Button*> *colorButtons) :Button(normal, clicked, hovered, location, scale) {
		this->curr_col = curr_col;
		this->colorButtons = colorButtons;
	}
	
	void action() override {
		for (Button *b : *colorButtons)
		{
			if (b->isClicked())
			{
				b->setState(state::state_normal);
			}
		}

		this->setState(state::state_clicked);
		if (this->isClicked()) {
			*this->curr_col = sf::Color::White;
		}
		else
		{
			*this->curr_col = sf::Color::Black;
		}
	}

	sf::Color getColor() override
	{
		return sf::Color::Black;
	}
};