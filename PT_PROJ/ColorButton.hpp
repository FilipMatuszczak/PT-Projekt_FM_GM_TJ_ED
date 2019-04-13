#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.hpp"
#include<vector>
using namespace sf;

class ColorButton : public Button {
public:
	sf::Color *curr_col;
	sf::Color color;
	std::vector<Button*> *colorButtons;
	ColorButton(
		sf::Texture* normal,
		sf::Texture* clicked,
		sf::Texture* hovered,
		sf::Vector2f location,
		float scale,
		sf::Color *curr_col,
		sf::Color color,
		std::vector<Button*> *colorButtons
	) :Button(normal, clicked, hovered, location, scale) {
		this->curr_col = curr_col;
		this->color = color;
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
		*this->curr_col = color;
		

	}
};