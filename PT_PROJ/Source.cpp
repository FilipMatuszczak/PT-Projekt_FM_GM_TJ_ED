#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "button.hpp"

using namespace sf;
int main()
{
	srand(time(NULL));

	std::vector<sf::VertexArray> vertices;

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
	Texture* texture_normal = new Texture();
	Texture* texture_hover = new Texture(); 
	Texture* texture_clicked = new Texture();

	if (!texture_normal->loadFromFile("./icons/clear_free.png", sf::IntRect(0, 0, 572, 572)))
	{
		std::cout << "cos poszlo nie tak";
	}
	if (!texture_hover->loadFromFile("./icons/clear_hover.png", sf::IntRect(0, 0, 572, 572)))
	{
		std::cout << "cos poszlo nie tak";
	}	if (!texture_clicked->loadFromFile("./icons/clear_pressed.png", sf::IntRect(0, 0, 572, 572)))
	{
		std::cout << "cos poszlo nie tak";
	}

	Button b(texture_normal, texture_clicked, texture_hover, sf::Vector2f(0,0));
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
		b.checkHover(sf::Vector2f(sf::Mouse::getPosition(window)));
		b.checkNormal(sf::Vector2f(sf::Mouse::getPosition(window)));
		window.draw(construction);
		//window.draw(*b.getSprite());
		window.display();
	}


	return 0;
}