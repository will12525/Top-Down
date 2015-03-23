#ifndef _TILE_H
#define _TILE_H

class Tile
{
public:
	Tile(int xcoord, int ycoord, int idnum);
	int getX();
	
	int getY();
	
	int getID();
	
	int setID(int idnum);
private:
	int x, y, id;

};
#endif