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
	std::vector<Button*> *toolButtons;
	ColorButton(
		sf::Texture* normal,
		sf::Texture* clicked,
		sf::Texture* hovered,
		sf::Vector2f location,
		float scale,
		sf::Color *curr_col,
		sf::Color color,
		std::vector<Button*> &colorButtons,
		std::vector<Button*> &toolButtons
	) :Button(normal, clicked, hovered, location, scale) {
		this->curr_col = curr_col;
		this->color = color;
		this->colorButtons = &colorButtons;
		this->toolButtons = &toolButtons;
	}

	void action() override {
		for (Button *b : *colorButtons)
		{
			if (b->isClicked())
			{
				b->setState(state::state_normal);
			}
		}
		int inc = 0;
		for (Button *b : *toolButtons)
		{
			if (inc == 0)
			{
				b->setState(state::state_clicked);
			}
			else if (inc == 1)
			{
				b->setState(state::state_normal);
			}
			inc++;
		}
		this->setState(state::state_clicked);
		*this->curr_col = color;
		

	}

	sf::Color getColor() override {
		return this->color;
	}
};