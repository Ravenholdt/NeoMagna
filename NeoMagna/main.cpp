
#include <iostream>
#include <thread>

#include <string> 
#include <sstream>

#include "main.h"

#include "generateSystem.h"

std::string test;
//int test;

int main()
{
	std::thread mainWindowThread(mainWindow);

	int seed = 0;

	while (true) {
		Sleep(1000);

		std::ostringstream StrP2;
		int tmpint = generateSystem(seed*seed);
		StrP2 << tmpint;
		//std::string tmpstr(StrP2.str());
		//test = tmpstr;
		test = StrP2.str();
		std::cout << test << ", " << std::endl;
		seed++;
	}

	mainWindowThread.join();

	return 0;
}

void mainWindow() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "NeoMagna");
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	font.loadFromFile("Fonts/space.ttf");

	sf::Text text("Hello World 1", font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	text.setPosition(50, 50);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Green);

		text.setString(test);

		window.draw(text);

		window.display();
	}
}
