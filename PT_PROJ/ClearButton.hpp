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
	std::vector<std::vector<sf::VertexArray>> *vertices;
	ClearButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale, std::vector<std::vector<sf::VertexArray>> *vertices) :Button(normal, clicked, hovered, location, scale)
	{
		this->vertices = vertices;
	}

	void action() override {
		for (auto &vertice : *vertices) {
			vertice.clear();
			sf::VertexArray arr;
			arr.setPrimitiveType(sf::LinesStrip);
			vertice.push_back(arr);
			this->setState(state::state_hovered);
		}
	}
};