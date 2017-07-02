
#include "generateSystem.h"

int generateSystem(int seed) {
	srand(seed);
	int planets = rand()%11 + 4;
	return planets;
}

// Constructor
Star::Star(sf::Vector2f position) {
	pos = position;
	radius = 20;
}

// Get values
sf::Vector2f  Star::position() { return pos; }
float Star::getSize() { return radius; }
int Star::getID() { return systemID; }