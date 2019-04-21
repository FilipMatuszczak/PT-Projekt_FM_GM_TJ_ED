#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>

void initialize_drawer(std::vector<std::vector<sf::VertexArray>> &vertices) {

	std::vector<sf::VertexArray> v1;
	v1.push_back(VertexArray());
	v1[0].setPrimitiveType(sf::LinesStrip);
	vertices.push_back(v1);
	
	std::vector<sf::VertexArray> v2;
	v2.push_back(VertexArray());
	v2[0].setPrimitiveType(sf::LinesStrip);
	vertices.push_back(v2);

	std::vector<sf::VertexArray> v3;
	v3.push_back(VertexArray());
	v3[0].setPrimitiveType(sf::LinesStrip);
	vertices.push_back(v3);

	std::vector<sf::VertexArray> v4;
	v4.push_back(VertexArray());
	v4[0].setPrimitiveType(sf::LinesStrip);
	vertices.push_back(v4);
}

void draw(sf::Vector2f mousePos, sf::Color curr_col, sf::Window &window, std::vector<std::vector<sf::VertexArray>> &vertices) {
	vertices[0][vertices[0].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - window.getPosition().x, mousePos.y - window.getPosition().y ), curr_col));
	vertices[1][vertices[1].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x+1 - window.getPosition().x, mousePos.y - window.getPosition().y), curr_col));
	vertices[2][vertices[2].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x+1 - window.getPosition().x, mousePos.y+1 - window.getPosition().y), curr_col));
	vertices[3][vertices[3].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - window.getPosition().x, mousePos.y+1 - window.getPosition().y), curr_col));
}
