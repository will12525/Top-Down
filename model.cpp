#include "Model.h"
#include "menu.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "GrassTile.cpp"
#include "voidTile.cpp"

using namespace std;

// Constructor initializes the object
Model::Model(int width, int height) {
	xOffset = 0;
	yOffset = 0;
	loadTiles("testmap.txt");
	check = START;
}
int Model::getXOffset()
{
	return xOffset;
}

int Model::getYOffset()
{
	return yOffset;
}

vector<Tile> Model::getTiles()
{
	return tiles;
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

void Model::go(Direction d)
{
	if(d == UP)
	{
		yOffset++;
		cout << "Debug: Up" << endl;
	}
	else if(d == DOWN)
	{
		yOffset--;
		cout << "Debug: Down" << endl;
	}
	else if(d == LEFT)
	{
		xOffset++;
		cout << "Debug: Left" << endl;
	}
	else if(d == RIGHT)
	{
		xOffset--;
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

	int yCoord=0;
	int xCoord=0;

	while(tileFile >> nextLine)
	{
		
		if(readTiles)
		{
			
			if(nextLine == "[layer]")
			{
				cout<<"empty line, creation limited to first layer for now."<<endl;
				cout<<"Created "<<tiles.size()<<" tiles" <<endl;
				//remove return to allow all layers
				return;
				readTiles=false;
				continue;
			}
			
			for(int k=0;k<nextLine.length();k++)
			{
				if(nextLine.at(k)==',')
				{
					continue;
				}
				int tileId=0;
				string holder="";
				for(int j=k;j<nextLine.length();j++)
				{
					if(nextLine.at(j)==',')
					{
						k=j;
						break;
					}
					
					holder=holder+nextLine.at(j);
					
				}
				tileId=atoi(holder.c_str());
	
				Tile * tile;
				
				//to create a new tile, create the class for it by using the GrassTile
				//or VoidTile class as a template then create a switch with its case
				//referring to the id number saved on the text document.
				switch(tileId)
				{
					case 1:
						tile = new GrassTile(xCoord,yCoord,1);
						tiles.push_back(*tile);
						break;
					default:
						tile = new VoidTile(xCoord,yCoord,0);
						tiles.push_back(*tile);
						break;
				}
				xCoord++;
			}
			xCoord=0;
		}		
		yCoord++;
	
		if(nextLine == "data=")
		{
		
			readTiles=true;
			yCoord=0;
		}
		
	}
	
}

