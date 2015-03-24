#ifndef _TILE_H
#define _TILE_H

class Tile
{
public:
	Tile() {}
	Tile(int xcoord, int ycoord, int idnum);
	int getX();
	
	int getY();
	
	int getID();
	
	int setID(int idnum);
protected:
	int x, y, id;

};
#endif