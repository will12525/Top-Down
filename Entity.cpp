#include "Entity.h"
#include <string>
using namespace std;



Entity::Entity(int xcoord, int ycoord, string name,)
{
	x = xcoord;
	y = ycoord;
	this->name = name;
	rotation=0;
}
