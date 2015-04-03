#ifndef _ENTITY_H
#define _ENTITY_H
#include <string>
using namespace std;

class Entity
{
public:
	Entity() {}
	Entity(int xcoord, int ycoord, string name);

	string getPath()
	{
		return path;
	}

	string getName() {
		return name;
	}

	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getRotation()
	{
		return rotation;
	}
	int setX(int x)
	{
		this->x=x;
	}
	int setY(int y)
	{
		this->y=y;
	}
	int setRotation(int r)
	{
		rotation=r;
	}
	
	bool death()
	{
		return dead;
	}
	void move();
	
protected:
	int x, y,rotation;
	string path,name;
	bool dead;

};
#endif