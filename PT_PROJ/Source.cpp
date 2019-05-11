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
#include "drawingInitialization.hpp"

using namespace sf;

int main()
{
	srand(time(NULL));

	std::vector<std::vector<sf::VertexArray>> vertices;

	initialize_drawer(vertices);

	bool L_locked = false;
	int size = 1;
	sf::Color curr_col = sf::Color::Black;
	sf::Vector2i last_Mouse_pos(0, 0);

	sf::RenderWindow window(sf::VideoMode(), "PPencil", sf::Style::Fullscreen);

	sf::RectangleShape menu;
	menu.setSize(sf::Vector2f(window.getSize().x, 70));
	menu.setOutlineColor(sf::Color::Black);
	menu.setOutlineThickness(5);
	menu.setFillColor(sf::Color(245, 222, 179, 255));
	menu.setPosition(0, 0);
	Texture currentWindow;
	sf::Vector2i Border_Offset(0, 0);
	std::vector<Button*> *Colorbuttons = new std::vector<Button*>();

	SaveButton saveButton = getSave(0, window.getSize().x, &window);
	ClearButton clearButton = getClear(1, &currentWindow, window.getSize().x);
	HandButton handButton = getHand(2, window.getSize().x);
	PlusButton plusButton = getPlus(3, window.getSize().x, &size);
	MinusButton minusButton = getMinus(4, window.getSize().x, &size);
	PenButton penButton = getPen(5, window.getSize().x);
	EraserButton eraserButton = getEraser(6, window.getSize().x, &curr_col);
	ColorButton blackButton = getBlack(7, window.getSize().x, &curr_col, Colorbuttons);
	ColorButton whiteButton = getWhite(8, window.getSize().x, &curr_col, Colorbuttons);
	ColorButton yellowButton = getYellow(9, window.getSize().x, &curr_col, Colorbuttons);
	ColorButton redButton = getRed(10, window.getSize().x, &curr_col, Colorbuttons);
	ColorButton greenButton = getGreen(11, window.getSize().x, &curr_col, Colorbuttons);
	ColorButton blueButton = getBlue(12, window.getSize().x, &curr_col, Colorbuttons);
	ColorButton purpleButton = getPurple(13, window.getSize().x, &curr_col, Colorbuttons);
	SettingsButton settingsButton = getSettings(14, window.getSize().x);
	ExitButton exitButton = getExit(15, window.getSize().x, &window);

	std::vector<Button*> buttons;
	
	buttons.push_back(&clearButton);
	buttons.push_back(&eraserButton);
	buttons.push_back(&handButton);
	buttons.push_back(&minusButton);
	buttons.push_back(&penButton);
	buttons.push_back(&plusButton);
	buttons.push_back(&saveButton);
	buttons.push_back(&settingsButton);
	buttons.push_back(&blackButton);
	buttons.push_back(&blueButton);
	buttons.push_back(&greenButton);
	buttons.push_back(&purpleButton);
	buttons.push_back(&redButton);
	buttons.push_back(&whiteButton);
	buttons.push_back(&yellowButton);
	buttons.push_back(&exitButton);

	Colorbuttons->push_back(&blackButton);
	Colorbuttons->push_back(&blueButton);
	Colorbuttons->push_back(&greenButton);
	Colorbuttons->push_back(&purpleButton);
	Colorbuttons->push_back(&redButton);
	Colorbuttons->push_back(&whiteButton);
	Colorbuttons->push_back(&yellowButton);

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
				currentWindow.create(window.getSize().x, window.getSize().y);
				currentWindow.update(window);

				for (auto &vertice : vertices) {
					vertice.clear();
					sf::VertexArray arr;
					arr.setPrimitiveType(sf::LinesStrip);
					vertice.push_back(arr);
				}
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
			draw(sf::Vector2f(sf::Mouse::getPosition()), curr_col, window, vertices,size);
		}

		window.clear(sf::Color::White);

		sf::Sprite sprite;
		sprite.setTexture(currentWindow);
		window.draw(sprite);

			for (int j = 0; j < vertices[0].size(); j++) {
				for (int i = 0; i < vertices.size(); i++)
				{
					window.draw(vertices[i][j]);
				}
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