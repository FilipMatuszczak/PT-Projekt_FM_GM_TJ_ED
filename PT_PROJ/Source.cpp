#include "SFML\Graphics.hpp"
#include <time.h> // srand()
#include <iostream>
#include <vector>


int main()
{

	srand(time(NULL)); // initialize rand() by using the current system time

	std::vector<sf::VertexArray> vertices; // vector in wich all vertexArrays (lines, rectangles) will be stored

	enum class states { Line, Rectangle, Circle }; // current drawing mode
	states current_state = states::Line;

	// Lines
	vertices.push_back(sf::VertexArray()); // 1st line
	vertices[0].setPrimitiveType(sf::LinesStrip); // PrimitiveType of the 1st line: see https://www.sfml-dev.org/tutorials/2.4/graphics-vertex-array.php
	bool L_locked = false; // (only when in line mode) 


	// Rectangles
	bool R_first_MB_released = false; // (only when in rectangle mode)
	sf::Vector2f R_first; // position of the 1st mouse button released
	sf::Vector2f R_second; // position of the 2nd mouse button released
	bool R_locked = false;
	sf::VertexArray construction(sf::Quads); // construction rectangle (preview)
	for (int i = 0; i < 16; i++)
		construction.append(sf::Vertex());

	//sf::RectangleShape s;
	//std::cout << "RectangleShape: " << sizeof(s) << ", VertexArray: " << sizeof(construction) << std::endl; std::cin.get(); std::cin.get(); // RectangleShape vs VertexArray


	sf::Color curr_col = sf::Color::Black; // color 
	sf::Vector2i last_Mouse_pos(0, 0);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "µPaint", sf::Style::Close, sf::ContextSettings(0, 0, 0)); // where everythings drawn to
	window.setFramerateLimit(60);

	sf::Vector2i Border_Offset(-5, -25); // See (peculiarities in the 1st part: https://steemit.com/steemstem/@numbo/c-sfml-paint-a-simple-drawing-program )

	while (window.isOpen())
	{

		// Events
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::KeyPressed) // closing window
				if (event.key.code == sf::Keyboard::Key::Escape)
					window.close();
			if (event.type == sf::Event::Closed) // closing window
				window.close();

			if (event.type == sf::Event::KeyPressed) // Switch between drawing modes
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
					if (R_first_MB_released) // Only when the 1st button is already defined, define the second one
					{
						R_second = sf::Vector2f(sf::Mouse::getPosition() - window.getPosition() + Border_Offset);
						R_locked = true;
					}
				}
				else if (current_state == states::Circle)
				{
					// DIY
				}

			}

			if (event.type == sf::Event::MouseButtonReleased)
			{

				if (current_state == states::Line)
				{
					// Add a new line
					vertices.push_back(sf::VertexArray());
					vertices[vertices.size() - 1].setPrimitiveType(sf::LinesStrip);

					L_locked = false; // Reset line
				}
				else if (current_state == states::Rectangle)
				{
					if (!R_first_MB_released) // Define the 1st position
					{
						R_first_MB_released = true;
						R_first = sf::Vector2f(sf::Mouse::getPosition() - window.getPosition() + Border_Offset);
					}
					if (R_first_MB_released && R_locked) // Set the final position -> save and reset
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
					// DIY
				}



			}
		} // End Events


		// Construction of a line
		if (L_locked)
		{
			if (last_Mouse_pos != sf::Mouse::getPosition()) // Only add, when the mouse has moved (save memory)
			{
				//.append(Position, Farbe) : .append(MousePos - WindowPos + MouseOffset, curr_col)
				vertices[vertices.size() - 1].append(sf::Vertex(sf::Vector2f(sf::Mouse::getPosition().x - window.getPosition().x + Border_Offset.x, sf::Mouse::getPosition().y - window.getPosition().y + Border_Offset.y), curr_col));

				last_Mouse_pos = sf::Mouse::getPosition();
			}
		}

		// Construction of a rectangle
		if (R_locked)
		{
			if (last_Mouse_pos != sf::Mouse::getPosition())
			{
				//calculate (see Functional description (behind the scenes))
				// = QuadsStrip DIY

				sf::Vector2f render_mouse_pos(sf::Mouse::getPosition() - window.getPosition() + Border_Offset); // see mouse coordinate mapping in part 1

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

				last_Mouse_pos = sf::Mouse::getPosition(); // reset mouse position

			}
		}

		//curr_col = sf::Color::Color(rand() % 255, rand() % 255, rand() % 255);


		//std::cout << "vertices in line " << lines_number << ": " << vertices[lines_number].getVertexCount() << std::endl;

		

		window.clear(sf::Color::White); // delete the current scene with a specific color

		// draw everything
		for (int i = 0; i < vertices.size(); i++)
		{
			window.draw(vertices[i]);
		}

		window.draw(construction); // construction rectangle -> preview

		window.display();
	}


	return 0;
}