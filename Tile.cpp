#include "Tile.h"
#include <string>
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
string Tile::getPath()
{
	return path;
}
int Tile::getY()
{
	return y;
}
	

int Tile::setID(int idnum)
{
	id = idnum;
}
