#pragma once
#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "SFML\System\String.hpp"
#include "button.hpp"
using namespace sf;

class SaveButton :public Button {
public:
	sf::Window * window;
	SaveButton(sf::Texture* normal, sf::Texture* clicked, sf::Texture* hovered, sf::Vector2f location, float scale, sf::Window * window) :Button(normal, clicked, hovered, location, scale) 
	{
		this->window = window;
	}

	void action() override {
		std::cout << "Save!";

		

			sf::Texture texture, tlo;
			texture.create(window->getSize().x, window->getSize().y);
			texture.update(*window);


			if (texture.copyToImage().saveToFile("screen.png"))
			{
				std::cout << "screenshot saved " << std::endl;

				tlo.loadFromFile("screen.png", sf::IntRect(0, 75, 1920, 1005));
				tlo.copyToImage().saveToFile("screen.png");

			}
			else
			{
				std::cout << "save failed " << std::endl;
			}


	
};



};