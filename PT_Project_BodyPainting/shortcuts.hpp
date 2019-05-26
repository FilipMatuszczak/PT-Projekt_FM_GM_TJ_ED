#pragma once

#pragma once

#include "SFML\Graphics.hpp"
#include <vector>
#include "SFML\System\String.hpp"
#include "button.h"
#include <string>


void detectShortcut(std::vector<Button*> &actionButtons, std::vector<std::vector<sf::VertexArray>> &vertices)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		actionButtons[0]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		actionButtons[1]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		actionButtons[2]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		for (auto &vertice : vertices) {
			vertice.clear();
			sf::VertexArray arr;
			arr.setPrimitiveType(sf::LinesStrip);
			vertice.push_back(arr);
		}
		actionButtons[3]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
	{
		actionButtons[4]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
	{
		actionButtons[5]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		actionButtons[6]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		actionButtons[7]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		actionButtons[8]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		actionButtons[9]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		actionButtons[10]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		actionButtons[11]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		actionButtons[12]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		actionButtons[13]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		actionButtons[14]->action();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		actionButtons[15]->action();
	}


}