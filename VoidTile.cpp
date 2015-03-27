#include "Tile.h"
#include <string>
class VoidTile : public Tile
{
public:
	VoidTile(int xCoord,int yCoord,int id)
	{
		x = xCoord;
		y=yCoord;
		this->id=id;
		path = "tileset/1.png";
	}
	std::string getPath()
	{
		return path;
	}
private:
	std::string path;
};