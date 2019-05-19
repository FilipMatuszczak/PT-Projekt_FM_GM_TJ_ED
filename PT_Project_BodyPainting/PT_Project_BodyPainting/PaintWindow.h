#pragma once

#include "SFML\Graphics.hpp"
#include "button.h"
#include "PurpleDetector.h"

class PaintWindow
{
private:
	bool L_locked = false;
	bool var = false;

	int size = 1;
	sf::Color curr_col;
	sf::Vector2i last_Mouse_pos;
	sf::Vector2i Border_Offset; 
	//sf::RenderWindow window;
	sf::Texture currentWindow;
	sf::RectangleShape menu;
	std::vector<std::vector<sf::VertexArray> > vertices;
	std::vector<Button*> Colorbuttons;
	std::vector<Button*> Toolbuttons;
	std::vector<Button*> buttons;

	PurpleDetector * purpleDetector;
	sf::Vector2i lastPointerPos;
	
	void CreateMenu();
	void CreateButtons();

public:
	PaintWindow();
	~PaintWindow();

	void run();
};

