#include "Tile.h"
#include <string>
class TreeTile : public Tile
{
public:
	TreeTile(int x,int y,int id)
	{
		this->x = x;
		this->y = y;
		this->id = id;
		path = "tileset/2.png";
	}

};
