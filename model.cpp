#include "Model.h"
#include "menu.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include "GrassTile.cpp"
#include "DirtTile.cpp"
#include "voidTile.cpp"
#include "TreeTile.cpp"
#include "PlayerEntity.cpp"
#include "Bullet.cpp"

using namespace std;

// Constructor initializes the object
Model::Model(int width, int height) {
	xOffset = 0;
	yOffset = 0;
	loadTiles("testmap.txt");
	check = START;

}

PlayerEntity Model::getPlayer()
{
	return player;
}

int Model::getXOffset()
{
	return player.getX();
}

int Model::getYOffset()
{
	return player.getY();
}

void Model::setXOffset(int x){
	xOffset=x;
}
void Model::setYOffset(int x){
	yOffset=x;
}

vector<Tile> Model::getTiles()
{
	return tiles;
}

vector<Entity> Model::getEntities(){
	return entities;
}

// Destructor deletes dynamically allocated memory
Model::~Model() {
}

void Model::handleKey(map <int, bool> keys)
{
	int speed = 0;
	int gunRot =0;

	//double dx=0, dy=0;

	cout << player.getX() << "  " << player.getY() << endl;


	if(keys[SDLK_UP])
	{
		speed=-10;
		//cout << "Debug: Up" << endl;
	}
	else if(keys[SDLK_DOWN])
	{
		speed+=10;
		//cout << "Debug: Down" << endl;
	}

	if(keys[SDLK_LEFT])
	{
		player.setRotation(player.getRotation()+5);

		//cout << "Debug: Left" << endl;
	}
	if(keys[SDLK_RIGHT])
	{
		player.setRotation(player.getRotation()-5);


		//cout << "Debug: Right" << endl;
	}

	if(keys[SDLK_ESCAPE])
	{
		//cout << "Debug: Escape" << endl;
	}

	if(keys[SDLK_RETURN])
	{
		//cout << "Debug: Enter" << endl;
	}

	if(keys[SDLK_SPACE])
	{
		//cout << "Debug: Space" << endl;
		shoot();
	}

	//move player
	player.move(speed);

}

void Model::shoot()
{
	Entity* bullet = new Bullet(player.getX(), player.getY(), "bullet");
	entities.push_back(*bullet);
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

	//player = new PlayerEntity(487,359, "will");

	//entities.push_back(*player);
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
					case 2:
						tile = new TreeTile(xCoord,yCoord,1);
						tiles.push_back(*tile);
						break;
					case 10:
						tile = new DirtTile(xCoord, yCoord, 10);
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
void Model::reset(){
	xOffset = 0;
	yOffset = 0;
	tiles.clear();
	entities.clear();
	loadTiles("testmap.txt");
}
