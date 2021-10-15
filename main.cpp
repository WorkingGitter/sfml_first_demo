#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(360,360),"Hello World", sf::Style::Default);	

	bool show_circle = false;

	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Blue);

	sf::RectangleShape rectangle(sf::Vector2f(300, 200));
	rectangle.setFillColor(sf::Color{0x05eaa5f});
	
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
				break;
			case sf::Event::EventType::KeyPressed:
				
				if (e.key.code == sf::Keyboard::C)
					show_circle = true;

				if (e.key.code == sf::Keyboard::R)
					show_circle = false;

				break;
			case sf::Event::EventType::TextEntered:
				if(e.text.unicode < 128)
					std::cout << "key pressed: " << (char)e.text.unicode << "\n";
				break;
			case sf::Event::EventType::Resized:
				std::cout << "window resized: " << e.size.height << ", " << e.size.width << "\n";
				break;
			}
		}

		if(show_circle)
			window.draw(circle);
		else
			window.draw(rectangle);

		window.display();
	}

	return 0;
}