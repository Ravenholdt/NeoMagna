
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <thread>

#include <string> 
#include <sstream> //int2string

#include "sfml.h"

#include "inputs.h"
#include "generateSystem.h"


void generate();
// Takes an integer as input
// Returns as a string.
std::string int2string(int integer);

void mainWindow();

void starWindow(/*Star star*/);

#endif
