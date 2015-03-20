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
	else if(d == ESCAPE)
	{
		xOffset++;
		cout << "Debug: Escape" << endl;
	}
	else if(d == ENTER)
	{
		xOffset++;
		cout << "Debug: Enter" << endl;
	}
	else if(d == SPACE)
	{
		xOffset++;
		cout << "Debug: Space" << endl;
	}
}

bool Model::gameOver() {
    return false;
}

