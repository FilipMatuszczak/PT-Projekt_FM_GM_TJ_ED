#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>

void initialize_drawer(std::vector<std::vector<sf::VertexArray>> &vertices) {

	for (int i = 0; i < 400; i++)
	{
		std::vector<sf::VertexArray> v;
		v.push_back(VertexArray());
		v[0].setPrimitiveType(sf::LinesStrip);
		vertices.push_back(v);
	}
}

int increase_size(sf::Vector2f mousePos, sf::Color curr_col, sf::Window &window, std::vector<std::vector<sf::VertexArray>> &vertices, int size, int start, int iterations)
{
	int moved = size - 1;

	int incr = - (size - 2);

	int var = (moved*moved) - 1;
	for (int i = 0; i < iterations; i++)
	{
		vertices[start][vertices[start].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x + moved - window.getPosition().x, mousePos.y + incr - window.getPosition().y), curr_col));
		start++;
		incr++;
	}

	incr = -(size - 2);

	for (int i = 0; i < iterations; i++)
	{
		vertices[start][vertices[start].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - moved - window.getPosition().x, mousePos.y + incr - window.getPosition().y), curr_col));
		start++;
		incr++;
	}

	incr = -(size - 2);

	for (int i = 0; i < iterations; i++)
	{
		vertices[start][vertices[start].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x + incr - window.getPosition().x, mousePos.y + moved - window.getPosition().y), curr_col));
		start++;
		incr++;
	}

	incr = -(size - 2);

	for (int i = 0; i < iterations; i++)
	{
		vertices[start][vertices[start].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x + incr - window.getPosition().x, mousePos.y - moved - window.getPosition().y), curr_col));
		start++;
		incr++;
	}

	vertices[start][vertices[start].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - moved - window.getPosition().x, mousePos.y - moved - window.getPosition().y), curr_col));
	vertices[start+1][vertices[start].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x + moved - window.getPosition().x, mousePos.y - moved - window.getPosition().y), curr_col));
	vertices[start+2][vertices[start].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - moved - window.getPosition().x, mousePos.y + moved - window.getPosition().y), curr_col));
	vertices[start+3][vertices[start].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x + moved - window.getPosition().x, mousePos.y + moved - window.getPosition().y), curr_col));

	return start + 4;
}

void draw(sf::Vector2f mousePos, sf::Color curr_col, sf::Window &window, std::vector<std::vector<sf::VertexArray>> &vertices, int size) {
	vertices[0][vertices[0].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - window.getPosition().x, mousePos.y - window.getPosition().y ), curr_col));
	vertices[1][vertices[1].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x+1 - window.getPosition().x, mousePos.y - window.getPosition().y), curr_col));
	vertices[2][vertices[2].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x-1 - window.getPosition().x, mousePos.y - window.getPosition().y), curr_col));
	vertices[3][vertices[3].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - window.getPosition().x, mousePos.y+1 - window.getPosition().y), curr_col));
	vertices[4][vertices[4].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - window.getPosition().x, mousePos.y - 1 - window.getPosition().y), curr_col));

	if (size > 1)
	{
		vertices[5][vertices[5].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x + 1 - window.getPosition().x, mousePos.y + 1 - window.getPosition().y), curr_col));
		vertices[6][vertices[6].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x + 1 - window.getPosition().x, mousePos.y - 1 - window.getPosition().y), curr_col));
		vertices[7][vertices[7].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - 1 - window.getPosition().x, mousePos.y + 1 - window.getPosition().y), curr_col));
		vertices[8][vertices[8].size() - 1].append(sf::Vertex(sf::Vector2f(mousePos.x - 1 - window.getPosition().x, mousePos.y - 1 - window.getPosition().y), curr_col));
		
	}
	if (size > 2)
	{
		int current = 3;
		int start = 9;
		int iterations = 3;
		while (current <= size)
		{
			start = increase_size(mousePos, curr_col, window, vertices, current, start, iterations);
			current++;
			iterations += 2;
		}
	}
}

