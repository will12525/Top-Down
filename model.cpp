#include "model.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;

// Constructor initializes the object
Model::Model(int width, int height) {
	xOffset = 0;
	yOffset = 0;
	tiles = new vector<Tile>();
	loadTiles("C://Users/lawrencew/Desktop");
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
		cout << "Debug: Escape" << endl;
	}
	else if(d == ENTER)
	{
		cout << "Debug: Enter" << endl;
	}
	else if(d == SPACE)
	{
		cout << "Debug: Space" << endl;
	}
}

bool Model::gameOver() {
    return false;
}
void Model::loadTiles(string path)
{

}

