
#include "main.h"

std::string test;


int main()
{
	// Creates a thread for the main window.
	std::thread mainWindowThread(mainWindow);

	std::thread generationThread(generate);


	//Waits for the main window to close before closing the program.
	mainWindowThread.join();

	return 0;
}


void generate() 
{
	int seed = 0;
	while (true) {
		Sleep(1000);
		test = int2string(generateSystem(seed*seed));
		seed++;
	}
}


// Takes an integer as input and returns it as a string.
std::string int2string(int integer) 
{
	std::ostringstream StrP2;
	StrP2 << integer;
	return StrP2.str();
}


// Renders the main window
void mainWindow() 
{
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

	// Text Menu Graphics
	sf::Texture systemMenuTexture;
	systemMenuTexture.loadFromFile("Textures/SystemMenu.png");
	sf::Sprite systemMenu;
	systemMenu.setTexture(systemMenuTexture);
	systemMenu.setPosition(400, 300);

	//Create TMP sun.
	Star newStar(sf::Vector2f(200.f, 200.f));

	// TMP Interface.
	float starX = 200, starY = 200;


	//Render variables
	bool leftMousePressed = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}

		// Clears the render buffer.
		window.clear(sf::Color::Green);

		// Create tmp-system icon.
		sf::CircleShape star(newStar.getSize());
		star.setOrigin(newStar.getSize(), newStar.getSize());
		star.setFillColor(sf::Color::White);

		text.setString(test);

		// TMP Interface.
		star.setPosition(starX, starY);
		/*if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "Mouse was pressed." << std::endl;
				if ((event.mouseButton.x < starX + 20 && event.mouseButton.x > starX - 20) && (event.mouseButton.y < starY + 20 && event.mouseButton.y > starY - 20)) {
					std::cout << "HIT!" << std::endl;
				}
			}
		}*/

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (!leftMousePressed) {
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				std::cout << "Mouse was pressed." << std::endl;
				if ((mousePosition.x < starX + 20 && mousePosition.x > starX - 20) && (mousePosition.y < starY + 20 && mousePosition.y > starY - 20)) {
					std::cout << "HIT!" << std::endl;

					// Star-window test
					//std::thread starWindowThread(starWindow/*, newStar*/);
				}
			}
			leftMousePressed = true;
		}
		else
		{
			leftMousePressed = false;
		}

		window.draw(star);
		window.draw(text);
		window.draw(systemMenu);



		// Render everything that has been drawn.
		window.display();
	}
}

void starWindow(/*Star star*/)
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "NeoMagna: " /*+ star.starName*/);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}