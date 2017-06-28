
#include "generateSystem.h"

int generateSystem(int seed) {
	srand(seed);
	int planets = rand()%11 + 4;
	return planets;
}