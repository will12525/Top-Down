#include "Tile.h"
using namespace std;

Tile::Tile(int xcoord, int ycoord, int idnum)
{
	x = xcoord;
	y = ycoord;
	id = idnum;
}
int Tile::getX()
{
	return x;
}

int Tile::getY()
{
	return y;
}
	
int Tile::getID()
{
	return id;
}
int Tile::setID(int idnum)
{
	id = idnum;
}
