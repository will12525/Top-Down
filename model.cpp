#include "model.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

// Constructor initializes the object
Model::Model(int width, int height) {
	xOffset = 0;
	yOffset = 0;
	tiles = new vector<Tile>();
	loadTiles("C:/Users/lawrencew/Top-Down.txt");
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
void Model::loadTiles(string path)
{
	ifstream tileFile;
	tileFile.open(path);
	string nextLine="";
	bool readTiles=false;
	while(nextLine>>tileFile)
	{
		if(readTiles)
		{
			if(strcmp(nextLine,"")==0)
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
		
	
		if(strcmp(nextLine,"data=")==0)
		{
			readTiles=true;
		}
	}
}

