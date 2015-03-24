#include "Tile.h"
#include <string>
class GrassTile : public Tile
{
public:
	GrassTile(int xCoord,int yCoord,int id)
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