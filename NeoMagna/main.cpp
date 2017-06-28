
#include <iostream>
#include <thread>

#include <string> 
#include <sstream> //int2string

#include "main.h"

#include "generateSystem.h"

std::string test;


int main()
{
	// Creates a thread for the main window.
	std::thread mainWindowThread(mainWindow);


	int seed = 0;
	while (true) {
		Sleep(1000);

		int systemNumber = generateSystem(seed*seed);
		test = int2string(systemNumber);
		
		std::cout << test << ", " << std::endl;
		seed++;
	}


	//Waits for the main window to close before closing the program.
	mainWindowThread.join();

	return 0;
}


// Takes an integer as input
// Returns as a string.
std::string int2string(int integer) {
	std::ostringstream StrP2;
	StrP2 << integer;
	return StrP2.str();
}


// Renders the main window
void mainWindow() {
	// Creates the main window and sets the framerate to the monitor framerate.
	sf::RenderWindow window(sf::VideoMode(600, 600), "NeoMagna");
	window.setVerticalSyncEnabled(true);

	// Loads a font into tha game
	sf::Font font;
	font.loadFromFile("Fonts/space.ttf");

	// Creates a text to be displayed on screen.
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



		// Clears the render buffer.
		window.clear(sf::Color::Green);



		text.setString(test);

		window.draw(text);



		// Render everything that has been drawn.
		window.display();
	}
}
