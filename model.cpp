#include "model.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Constructor initializes the object
Model::Model() {
	xOffset = 0;
	yOffset = 0;
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

void Model::go(Direction d)
{
	if(d == UP)
	{
		yOffset--;
		cout << "Debug: Up" << endl;
	}
	else if(d == DOWN)
	{
		yOffset++;
		cout << "Debug: Down" << endl;
	}
	else if(d == LEFT)
	{
		xOffset--;
		cout << "Debug: Left" << endl;
	}
	else if(d == RIGHT)
	{
		xOffset++;
		cout << "Debug: Right" << endl;
	}
}

bool Model::gameOver() {
    return false;
}

