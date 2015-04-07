#include "Tile.h"
#include <string>
class GrassTile : public Tile
{
public:
	GrassTile(int x,int y,int id)
	{
		this->x = x;
		this->y = y;
		this->id = id;
		path = "tileset/1.png";
	}

};
