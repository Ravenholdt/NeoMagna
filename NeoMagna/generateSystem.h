
#ifndef GENERATE_SYSTEM_H
#define GENERATE_SYSTEM_H

#include "sfml.h"

#include <stdlib.h>

int generateSystem(int);

class Star
{
public:
	Star(sf::Vector2f); // Constructor

	sf::Vector2f  position();
	float getSize();
	int getID();

	std::string starName;


private:
	int systemID;
	sf::Vector2f pos;
	float radius;
};

#endif
