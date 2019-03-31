#include "SFML\Graphics.hpp"
#include <time.h>
#include <iostream>
#include <vector>


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

	sf::RenderWindow window(sf::VideoMode(1280, 720), "µPaint", sf::Style::Close, sf::ContextSettings(0, 0, 0));
	window.setFramerateLimit(60);

	sf::Vector2i Border_Offset(-5, -25);

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

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Key::L)
					current_state = states::Line;
				else if (event.key.code == sf::Keyboard::Key::R)
					current_state = states::Rectangle;
				else if (event.key.code == sf::Keyboard::Key::C)
					current_state = states::Circle;
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (current_state == states::Line)
					L_locked = true;
				else if (current_state == states::Rectangle)
				{
					if (R_first_MB_released)
					{
						R_second = sf::Vector2f(sf::Mouse::getPosition() - window.getPosition() + Border_Offset);
						R_locked = true;
					}
				}
				else if (current_state == states::Circle)
				{
				}

			}

			if (event.type == sf::Event::MouseButtonReleased)
			{

				if (current_state == states::Line)
				{
					vertices.push_back(sf::VertexArray());
					vertices[vertices.size() - 1].setPrimitiveType(sf::LinesStrip);

					L_locked = false;
				}
				else if (current_state == states::Rectangle)
				{
					if (!R_first_MB_released)
					{
						R_first_MB_released = true;
						R_first = sf::Vector2f(sf::Mouse::getPosition() - window.getPosition() + Border_Offset);
					}
					if (R_first_MB_released && R_locked)
					{
						vertices.push_back(construction);

						R_first_MB_released = false;
						R_locked = false;

						curr_col = sf::Color::Color(rand() % 255, rand() % 255, rand() % 255);

						for (int i = 0; i < construction.getVertexCount(); i++)
							construction[i].position = sf::Vector2f(0, 0);
					}
				}
				else if (current_state == states::Circle)
				{
				}



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

		if (R_locked)
		{
			if (last_Mouse_pos != sf::Mouse::getPosition())
			{

				sf::Vector2f render_mouse_pos(sf::Mouse::getPosition() - window.getPosition() + Border_Offset);

				construction[0] = sf::Vertex(R_first, curr_col);
				construction[1] = sf::Vertex(R_second, curr_col);
				construction[2] = sf::Vertex(sf::Vector2f(render_mouse_pos.x - (R_second.x - R_first.x), R_second.y), curr_col);
				construction[3] = sf::Vertex(sf::Vector2f(render_mouse_pos.x, R_first.y), curr_col);

				construction[4] = sf::Vertex(construction[3].position, curr_col);
				construction[5] = sf::Vertex(construction[2].position, curr_col);
				construction[6] = sf::Vertex(sf::Vector2f(render_mouse_pos.x - (R_second.x - R_first.x), render_mouse_pos.y - (R_second.y - R_first.y)), curr_col);
				construction[7] = sf::Vertex(sf::Vector2f(render_mouse_pos), curr_col);

				construction[8] = sf::Vertex(construction[7].position, curr_col);
				construction[9] = sf::Vertex(construction[6].position, curr_col);
				construction[10] = sf::Vertex(sf::Vector2f(construction[1].position.x, construction[6].position.y), curr_col);
				construction[11] = sf::Vertex(sf::Vector2f(construction[0].position.x, construction[7].position.y), curr_col);

				construction[12] = sf::Vertex(construction[11].position, curr_col);
				construction[13] = sf::Vertex(construction[10].position, curr_col);
				construction[14] = sf::Vertex(construction[1].position, curr_col);
				construction[15] = sf::Vertex(construction[0].position, curr_col);

				last_Mouse_pos = sf::Mouse::getPosition();

			}
		}


		window.clear(sf::Color::White);

		for (int i = 0; i < vertices.size(); i++)
		{
			window.draw(vertices[i]);
		}

		window.draw(construction);

		window.display();
	}


	return 0;
}