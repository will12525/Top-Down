#include "Entity.h"
#include <string>

using namespace std;

class PlayerEntity: public Entity
{
public:
	PlayerEntity(int xcoord,int ycoord,string name)
	{
		x=xcoord;
		y=ycoord;
		this->name=name;
		path="tileset/TankBottom.png";
		dead=false;
		rotation=0;
	}
	


};