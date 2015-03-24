#include "Model.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

// Constructor initializes the object
Model::Model(int width, int height) {
	xOffset = 0;
	yOffset = 0;
	loadTiles("C:/Users/lawrencew/Top-Down/testmap.txt");
}
int Model::getXOffset()
{
	return xOffset;
}

int Model::getYOffset()
{
	return yOffset;
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
	else if(d == RETURN)
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
	ifstream tileFile;
	tileFile.open(path.c_str());
	string nextLine="";
	bool readTiles=false;
	while(tileFile >> nextLine)
	{
		if(readTiles)
		{
			if(nextLine == "")
			{
				readTiles=false;
				continue;
			}
			
			for(int k=0;k<nextLine.length();k++)
			{
				if(nextLine.at(k)==',')
				{
					continue;
				}
				char tileId=nextLine.at(k);
			}
			
			
		}
		
	
		if(nextLine == "data")
		{
			readTiles=true;
		}
	}
}

