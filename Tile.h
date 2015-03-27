#ifndef _TILE_H
#define _TILE_H
#include <string>
using namespace std;

class Tile
{
public:
	Tile() {}
	Tile(int xcoord, int ycoord, int idnum);
	int getX();
	
	int getY();
	
	string getPath();
	
	int getID() {
		return id;
	}
	
	int setID(int idnum);
protected:
	int x, y, id;
	string path;

};
#endif