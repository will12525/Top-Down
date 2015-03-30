#ifndef _TILE_H
#define _TILE_H
#include <string>
using namespace std;

class Tile
{
public:
	Tile() {}
	Tile(int xcoord, int ycoord, int idnum);

	string getPath()
	{
		return path;
	}

	int getID() {
		return id;
	}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	int setID(int idnum);
protected:
	int x, y, id;
	string path;

};
#endif
