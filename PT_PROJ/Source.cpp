#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "button.hpp"
#include "ClearButton.hpp"
#include "EraserButton.hpp"
#include "HandButton.hpp"
#include "MinusButton.hpp"
#include "PenButton.hpp"
#include "PlusButton.hpp"
#include "SaveButton.hpp"
#include "SettingsButton.hpp"
#include "buttons_initialization.hpp"
#include <vector>
using namespace sf;
int main()
{
	srand(time(NULL));

	std::vector<sf::VertexArray> vertices;

	sf::RectangleShape menu;
	menu.setSize(sf::Vector2f(1200, 70));
	menu.setOutlineColor(sf::Color::Black);
	menu.setOutlineThickness(5);
	menu.setFillColor(sf::Color(245,222,179,255));
	menu.setPosition(0, 0);

	enum class states { Line, Rectangle, Circle };
	states current_state = states::Line;

	vertices.push_back(sf::VertexArray());
	vertices[0].setPrimitiveType(sf::LinesStrip);
	bool L_locked = false;

	bool R_first_MB_released = false;
	sf::Vector2f R_first;
	sf::Vector2f R_second;
	bool R_locked = false;
	sf::VertexArray construction(sf::Quads);
	for (int i = 0; i < 16; i++)
		construction.append(sf::Vertex());

	sf::Color curr_col = sf::Color::Black;
	sf::Vector2i last_Mouse_pos(0, 0);

	sf::RenderWindow window(sf::VideoMode(1200, 800), "PPencil", sf::Style::Close, sf::ContextSettings(0, 0, 0));
	window.setFramerateLimit(60);

	sf::Vector2i Border_Offset(-5, -25);

	ClearButton clearButton = getClear(1);
	EraserButton eraserButton = getEraser(6);
	HandButton handButton = getHand(2);
	MinusButton minusButton = getMinus(4);
	PenButton penButton = getPen(5);
	PlusButton plusButton = getPlus(3);
	SaveButton saveButton = getSave(0);
	SettingsButton settingsButton = getSettings(7);

	std::vector<Button*> buttons;
	buttons.push_back(&clearButton);
	buttons.push_back(&eraserButton);
	buttons.push_back(&handButton);
	buttons.push_back(&minusButton);
	buttons.push_back(&penButton);
	buttons.push_back(&plusButton);
	buttons.push_back(&saveButton);
	buttons.push_back(&settingsButton);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Key::Escape)
					window.close();
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
					L_locked = true;
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{

					vertices.push_back(sf::VertexArray());
					vertices[vertices.size() - 1].setPrimitiveType(sf::LinesStrip);

					for (Button *b : buttons)
					{
						if (b->checkClicked(sf::Vector2f(sf::Mouse::getPosition(window)))) {
							b->action();
						}
					}

					L_locked = false;
			}
		}

		if (L_locked)
		{
			if (last_Mouse_pos != sf::Mouse::getPosition())
			{
				vertices[vertices.size() - 1].append(sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x - window.getPosition().x + Border_Offset.x, sf::Mouse::getPosition().y - window.getPosition().y + Border_Offset.y), curr_col));

				last_Mouse_pos = sf::Mouse::getPosition();
			}
		}

		window.clear(sf::Color::White);

		for (int i = 0; i < vertices.size(); i++)
		{
			window.draw(vertices[i]);
		}

		window.draw(menu);
		for (Button *b : buttons)
		{
			b->checkHover(sf::Vector2f(sf::Mouse::getPosition(window)));
			b->checkNormal(sf::Vector2f(sf::Mouse::getPosition(window)));
			window.draw(*b->getSprite());
		}

		window.display();
	}


	return 0;
}