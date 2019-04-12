#pragma once

#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.hpp"
#include <string>
#include <vector>
#include "ClearButton.hpp"
#include "EraserButton.hpp"
#include "HandButton.hpp"
#include "MinusButton.hpp"
#include "PenButton.hpp"
#include "PlusButton.hpp"
#include "SaveButton.hpp"
#include "SettingsButton.hpp"

using namespace sf;
int incr = 65;
void loadTexture(Texture &texture, std::string path) {
	if (!texture.loadFromFile(path, sf::IntRect(0, 0, 572, 572)))
	{
		std::cout << "Failed to load an icon";
	}
}

ClearButton getClear(int i)
{
	Texture* texture_clear_normal = new Texture();
	Texture* texture_clear_hover = new Texture();
	Texture* texture_clear_clicked = new Texture();

	int x = incr *i;
	int y = 0;

	loadTexture(*texture_clear_normal, "./icons/clear_free.png");
	loadTexture(*texture_clear_hover, "./icons/clear_hover.png");
	loadTexture(*texture_clear_clicked, "./icons/clear_pressed.png");

	return ClearButton(texture_clear_normal, texture_clear_clicked, texture_clear_hover, sf::Vector2f(x, y), 0.1);
}

SaveButton getSave(int i)
{
	Texture* texture_save_normal = new Texture();
	Texture* texture_save_hover = new Texture();
	Texture* texture_save_clicked = new Texture();

	int x = incr * i;
	int y = 0;

	loadTexture(*texture_save_normal, "./icons/save_free.png");
	loadTexture(*texture_save_hover, "./icons/save_hover.png");
	loadTexture(*texture_save_clicked, "./icons/save_pressed.png");

	return SaveButton(texture_save_normal, texture_save_clicked, texture_save_hover, sf::Vector2f(x, y), 0.1);
}

HandButton getHand(int i)
{
	Texture* texture_hand_normal = new Texture();
	Texture* texture_hand_hover = new Texture();
	Texture* texture_hand_clicked = new Texture();

	int x = incr * i;
	int y = 0;

	loadTexture(*texture_hand_normal, "./icons/hand_free.png");
	loadTexture(*texture_hand_hover, "./icons/hand_hover.png");
	loadTexture(*texture_hand_clicked, "./icons/hand_pressed.png");

	return HandButton(texture_hand_normal, texture_hand_clicked, texture_hand_hover, sf::Vector2f(x, y), 0.1);
}

PlusButton getPlus(int i)
{
	std::vector<Button> buttons;
	Texture* texture_plus_normal = new Texture();
	Texture* texture_plus_hover = new Texture();
	Texture* texture_plus_clicked = new Texture();

	int x = incr * i;
	int y = 0;

	loadTexture(*texture_plus_normal, "./icons/plus_free.png");
	loadTexture(*texture_plus_hover, "./icons/plus_hover.png");
	loadTexture(*texture_plus_clicked, "./icons/plus_pressed.png");

	return PlusButton(texture_plus_normal, texture_plus_clicked, texture_plus_hover, sf::Vector2f(x, y), 0.1);
}

MinusButton getMinus(int i)
{
	std::vector<Button> buttons;
	Texture* texture_minus_normal = new Texture();
	Texture* texture_minus_hover = new Texture();
	Texture* texture_minus_clicked = new Texture();

	int x = incr * i;
	int y = 0;

	loadTexture(*texture_minus_normal, "./icons/minus_free.png");
	loadTexture(*texture_minus_hover, "./icons/minus_hover.png");
	loadTexture(*texture_minus_clicked, "./icons/minus_pressed.png");

	return MinusButton(texture_minus_normal, texture_minus_clicked, texture_minus_hover, sf::Vector2f(x, y), 0.1);
}

EraserButton getEraser(int i)
{
	std::vector<Button> buttons;
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = incr * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/eraser_free.png");
	loadTexture(*texture_hover, "./icons/eraser_hover.png");
	loadTexture(*texture_clicked, "./icons/eraser_pressed.png");

	return EraserButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), 0.1);
}

SettingsButton getSettings(int i)
{
	std::vector<Button> buttons;
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = incr * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/settings_free.png");
	loadTexture(*texture_hover, "./icons/settings_hover.png");
	loadTexture(*texture_clicked, "./icons/settings_pressed.png");

	return SettingsButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), 0.1);
}

PenButton getPen(int i)
{
	std::vector<Button> buttons;
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = incr * i;

	loadTexture(*texture_normal, "./icons/pen_free.png");
	loadTexture(*texture_hover, "./icons/pen_hover.png");
	loadTexture(*texture_clicked, "./icons/pen_pressed.png");

	return PenButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, 0), 0.1);
}