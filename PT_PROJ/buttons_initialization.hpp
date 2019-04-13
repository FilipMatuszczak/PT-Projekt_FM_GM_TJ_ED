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
#include "ColorButton.hpp"
#include "ExitButton.hpp"

using namespace sf;
float scale = 0.12;
float divider = 15.6;
void loadTexture(Texture &texture, std::string path) {
	if (!texture.loadFromFile(path, sf::IntRect(0, 0, 572, 572)))
	{
		std::cout << "Failed to load an icon";
	}
}

ClearButton getClear(int i, std::vector<sf::VertexArray>* vertices, int windowSize)
{
	Texture* texture_clear_normal = new Texture();
	Texture* texture_clear_hover = new Texture();
	Texture* texture_clear_clicked = new Texture();

	int x = windowSize/ divider *i;
	int y = 0;

	loadTexture(*texture_clear_normal, "./icons/clear_free.png");
	loadTexture(*texture_clear_hover, "./icons/clear_hover.png");
	loadTexture(*texture_clear_clicked, "./icons/clear_pressed.png");

	return ClearButton(texture_clear_normal, texture_clear_clicked, texture_clear_hover, sf::Vector2f(x, y), scale, vertices);
}

SaveButton getSave(int i, int windowSize)
{
	Texture* texture_save_normal = new Texture();
	Texture* texture_save_hover = new Texture();
	Texture* texture_save_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_save_normal, "./icons/save_free.png");
	loadTexture(*texture_save_hover, "./icons/save_hover.png");
	loadTexture(*texture_save_clicked, "./icons/save_pressed.png");

	return SaveButton(texture_save_normal, texture_save_clicked, texture_save_hover, sf::Vector2f(x, y), scale);
}

HandButton getHand(int i, int windowSize)
{
	Texture* texture_hand_normal = new Texture();
	Texture* texture_hand_hover = new Texture();
	Texture* texture_hand_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_hand_normal, "./icons/hand_free.png");
	loadTexture(*texture_hand_hover, "./icons/hand_hover.png");
	loadTexture(*texture_hand_clicked, "./icons/hand_pressed.png");

	return HandButton(texture_hand_normal, texture_hand_clicked, texture_hand_hover, sf::Vector2f(x, y), scale);
}

PlusButton getPlus(int i, int windowSize)
{
	Texture* texture_plus_normal = new Texture();
	Texture* texture_plus_hover = new Texture();
	Texture* texture_plus_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_plus_normal, "./icons/plus_free.png");
	loadTexture(*texture_plus_hover, "./icons/plus_hover.png");
	loadTexture(*texture_plus_clicked, "./icons/plus_pressed.png");

	return PlusButton(texture_plus_normal, texture_plus_clicked, texture_plus_hover, sf::Vector2f(x, y), scale);
}

MinusButton getMinus(int i, int windowSize)
{
	Texture* texture_minus_normal = new Texture();
	Texture* texture_minus_hover = new Texture();
	Texture* texture_minus_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_minus_normal, "./icons/minus_free.png");
	loadTexture(*texture_minus_hover, "./icons/minus_hover.png");
	loadTexture(*texture_minus_clicked, "./icons/minus_pressed.png");

	return MinusButton(texture_minus_normal, texture_minus_clicked, texture_minus_hover, sf::Vector2f(x, y), scale);
}

EraserButton getEraser(int i, int windowSize, sf::Color *curr_col)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/eraser_free.png");
	loadTexture(*texture_hover, "./icons/eraser_hover.png");
	loadTexture(*texture_clicked, "./icons/eraser_pressed.png");

	return EraserButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale, curr_col);
}

SettingsButton getSettings(int i, int windowSize)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/settings_free.png");
	loadTexture(*texture_hover, "./icons/settings_hover.png");
	loadTexture(*texture_clicked, "./icons/settings_pressed.png");

	return SettingsButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale);
}

ExitButton getExit(int i, int windowSize, sf::Window * window)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/exit_free.png");
	loadTexture(*texture_hover, "./icons/exit_hover.png");
	loadTexture(*texture_clicked, "./icons/exit_hover.png");

	return ExitButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale, window);
}

PenButton getPen(int i, int windowSize)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;

	loadTexture(*texture_normal, "./icons/pen_free.png");
	loadTexture(*texture_hover, "./icons/pen_hover.png");
	loadTexture(*texture_clicked, "./icons/pen_pressed.png");

	return PenButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, 0), scale);
}

ColorButton getBlack(int i, int windowSize, sf::Color *curr_col, std::vector<Button*> *buttons)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/black_free.png");
	loadTexture(*texture_hover, "./icons/black_hover.png");
	loadTexture(*texture_clicked, "./icons/black_pressed.png");

	return ColorButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale, curr_col, sf::Color::Black, buttons);
}

ColorButton getBlue(int i, int windowSize, sf::Color *curr_col, std::vector<Button*> *buttons)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/blue_free.png");
	loadTexture(*texture_hover, "./icons/blue_hover.png");
	loadTexture(*texture_clicked, "./icons/blue_pressed.png");

	return ColorButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale, curr_col, sf::Color(52,152,219,255), buttons);
}

ColorButton getGreen(int i, int windowSize, sf::Color *curr_col, std::vector<Button*> *buttons)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/green_free.png");
	loadTexture(*texture_hover, "./icons/green_hover.png");
	loadTexture(*texture_clicked, "./icons/green_pressed.png");

	return ColorButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale, curr_col, sf::Color(46,204,113,255), buttons);
}

ColorButton getPurple(int i, int windowSize, sf::Color *curr_col, std::vector<Button*> *buttons)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/purple_free.png");
	loadTexture(*texture_hover, "./icons/purple_hover.png");
	loadTexture(*texture_clicked, "./icons/purple_pressed.png");

	return ColorButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale, curr_col, sf::Color(155,89,182,255), buttons);
}

ColorButton getRed(int i, int windowSize, sf::Color *curr_col, std::vector<Button*> *buttons)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/red_free.png");
	loadTexture(*texture_hover, "./icons/red_hover.png");
	loadTexture(*texture_clicked, "./icons/red_pressed.png");

	return ColorButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale, curr_col, sf::Color(231,76,60, 255), buttons);
}

ColorButton getWhite(int i, int windowSize, sf::Color *curr_col, std::vector<Button*>* buttons)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/white_free.png");
	loadTexture(*texture_hover, "./icons/white_hover.png");
	loadTexture(*texture_clicked, "./icons/white_pressed.png");

	return ColorButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale, curr_col, sf::Color::White, buttons);
}

ColorButton getYellow(int i, int windowSize, sf::Color *curr_col, std::vector<Button*>* buttons)
{
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture();
	Texture* texture_clicked = new Texture();

	int x = windowSize / divider * i;
	int y = 0;

	loadTexture(*texture_normal, "./icons/yellow_free.png");
	loadTexture(*texture_hover, "./icons/yellow_hover.png");
	loadTexture(*texture_clicked, "./icons/yellow_pressed.png");

	return ColorButton(texture_normal, texture_clicked, texture_hover, sf::Vector2f(x, y), scale, curr_col, sf::Color(241,196,15, 255), buttons);
}
