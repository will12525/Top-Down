#include "Tile.h"
#include <string>

class DirtTile : public Tile
{
public:
  DirtTile(int x, int y, int id)
  {
    this->x = x;
    this->y = y;
    this->id = id;

    path = "tileset/10.png";
  }
};
