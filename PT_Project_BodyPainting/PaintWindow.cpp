#include "PaintWindow.h"
#include "drawingInitialization.hpp"
#include "shortcuts.hpp"
#include "button.h"
#include "ClearButton.hpp"
#include "EraserButton.hpp"
#include "HandButton.hpp"
#include "MinusButton.hpp"
#include "PenButton.hpp"
#include "PlusButton.hpp"
#include "SaveButton.hpp"
#include "buttons_initialization.hpp"

using namespace sf;

void PaintWindow::CreateMenu()
{
}

void PaintWindow::CreateButtons()
{

}

PaintWindow::PaintWindow()
{
	purpleDetector = new PurpleDetector();
	if (!purpleDetector->isCameraOK())
		delete purpleDetector;

	initialize_drawer(vertices);

	curr_col = sf::Color::Black;
	last_Mouse_pos = sf::Vector2i(0, 0);
	CreateMenu();
	Border_Offset = Vector2i(0, 0);
	CreateButtons();

	lastPointerPos = Vector2f(0, 0);
}


PaintWindow::~PaintWindow()
{
	delete purpleDetector;

}

void PaintWindow::run()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "PPencil", sf::Style::Fullscreen);
	
	menu.setSize(sf::Vector2f(window.getSize().x, 70));
	menu.setOutlineColor(sf::Color::Black);
	menu.setOutlineThickness(5);
	menu.setFillColor(sf::Color(245, 222, 179, 255));
	menu.setPosition(0, 0);
	int confideceLevel = 0;
	SaveButton saveButton = getSave(0, window.getSize().x, &window);
	ClearButton clearButton = getClear(1, &currentWindow, window.getSize().x);
	HandButton handButton = getHand(2, window.getSize().x, &capture);
	PlusButton plusButton = getPlus(3, window.getSize().x, &size, vertices);
	MinusButton minusButton = getMinus(4, window.getSize().x, &size, vertices);
	PenButton penButton = getPen(5, window.getSize().x, &curr_col, Toolbuttons, Colorbuttons);
	EraserButton eraserButton = getEraser(6, window.getSize().x, &curr_col, Toolbuttons);
	ColorButton blackButton = getBlack(7, window.getSize().x, &curr_col, Colorbuttons, Toolbuttons);
	ColorButton whiteButton = getWhite(8, window.getSize().x, &curr_col, Colorbuttons, Toolbuttons);
	ColorButton yellowButton = getYellow(9, window.getSize().x, &curr_col, Colorbuttons, Toolbuttons);
	ColorButton redButton = getRed(10, window.getSize().x, &curr_col, Colorbuttons, Toolbuttons);
	ColorButton greenButton = getGreen(11, window.getSize().x, &curr_col, Colorbuttons, Toolbuttons);
	ColorButton blueButton = getBlue(12, window.getSize().x, &curr_col, Colorbuttons, Toolbuttons);
	ColorButton purpleButton = getPurple(13, window.getSize().x, &curr_col, Colorbuttons, Toolbuttons);
	ColorButton pinkButton = getPink(14, window.getSize().x, &curr_col, Colorbuttons, Toolbuttons);
	ExitButton exitButton = getExit(15, window.getSize().x, &window);
	penButton.setState(Button::state_clicked);
	std::vector<Button*> buttons;
	bool detect = false;
	buttons.push_back(&saveButton);
	buttons.push_back(&clearButton);
	buttons.push_back(&eraserButton);
	buttons.push_back(&handButton);
	buttons.push_back(&plusButton);
	buttons.push_back(&minusButton);
	buttons.push_back(&penButton);

	buttons.push_back(&blackButton);
	buttons.push_back(&whiteButton);
	buttons.push_back(&yellowButton);
	buttons.push_back(&redButton);
	buttons.push_back(&greenButton);
	buttons.push_back(&blueButton);
	buttons.push_back(&purpleButton);
	buttons.push_back(&pinkButton);
	buttons.push_back(&exitButton);

	Colorbuttons.push_back(&blackButton);
	Colorbuttons.push_back(&blueButton);
	Colorbuttons.push_back(&greenButton);
	Colorbuttons.push_back(&purpleButton);
	Colorbuttons.push_back(&redButton);
	Colorbuttons.push_back(&whiteButton);
	Colorbuttons.push_back(&yellowButton);
	Colorbuttons.push_back(&pinkButton);

	Toolbuttons.push_back(&penButton);
	Toolbuttons.push_back(&eraserButton);
	window.setFramerateLimit(200);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::KeyPressed)
				detectShortcut(buttons);
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

		if (capture) {
			detect = purpleDetector->detect();
			if (detect)
			{
				confideceLevel++;
			}

			if (confideceLevel > 1000)
			{
				confideceLevel = 20;
			}

			if (!detect) {
				confideceLevel = 0;
				for (auto &vertice : vertices) {
					vertice.clear();
					sf::VertexArray arr;
					arr.setPrimitiveType(sf::LinesStrip);
					vertice.push_back(arr);
					var = false;
				}
			}
			if (confideceLevel > 5)
			{
				if (purpleDetector->getX() > 0 && purpleDetector->getY() > 0 && purpleDetector->getX() < window.getSize().x && purpleDetector->getY() < window.getSize().y)
				{
					float x_proportion = (float)window.getSize().x / (float)purpleDetector->getResolution().x;
					float y_proportion = (float)window.getSize().y / (float)purpleDetector->getResolution().y;
					lastPointerPos = sf::Vector2f(purpleDetector->getX()*x_proportion, purpleDetector->getY()*y_proportion);
					draw(lastPointerPos, curr_col, window, vertices, size);
				}
			}
			else
			{
				
				for (auto &vertice : vertices) {
					vertice.clear();
					sf::VertexArray arr;
					arr.setPrimitiveType(sf::LinesStrip);
					vertice.push_back(arr);
					var = false;
				}
			}
		}
		else {
			confideceLevel = 0;
			if (L_locked)
			{
				sf::Vector2i pos = sf::Mouse::getPosition();
				draw(sf::Vector2f(pos), curr_col, window, vertices, size);

				last_Mouse_pos = pos;
			}
		}

		window.clear(sf::Color::White);

		sf::Sprite sprite;
		sprite.setTexture(currentWindow);
		window.draw(sprite);


		for (int i = 0; i < vertices.size(); i++)
		{
			for (int j = 0; j < vertices[0].size(); j++) {
				window.draw(vertices[i][j]);
				if (vertices[i][j].getVertexCount() == 2)
				{
					vertices[i].clear();
					sf::VertexArray arr;
					arr.setPrimitiveType(sf::LinesStrip);
					vertices[i].push_back(arr);
					var = true;
				}
			}
		}


		window.draw(menu);
		for (Button *b : buttons)
		{
			b->checkHover(sf::Vector2f(sf::Mouse::getPosition(window)));
			b->checkNormal(sf::Vector2f(sf::Mouse::getPosition(window)));
			window.draw(*b->getSprite());
		}
		if (var == true && detect && capture)
		{
			currentWindow.create(window.getSize().x, window.getSize().y);
			currentWindow.update(window);
			draw(sf::Vector2f(lastPointerPos), curr_col, window, vertices, size);
			var = false;
		}
		else if (var == true && !capture)
		{
			currentWindow.create(window.getSize().x, window.getSize().y);
			currentWindow.update(window);
			draw(sf::Vector2f(last_Mouse_pos), curr_col, window, vertices, size);
			var = false;
		}
		window.display();

	}
}
