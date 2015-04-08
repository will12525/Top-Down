#ifndef _PLAYERENTITY_CPP
#define _PLAYERENTITY_CPP

#include "Entity.h"
#include <string>
#include <iostream>

using namespace std;

class PlayerEntity: public Entity
{
public:
	PlayerEntity()
	//PlayerEntity(double x,double y,string name)
	{
		this->x=487;
		this->y=359;
		this->name="will";
		path="tileset/TankBottom.png";
		dead=false;
		rotation=0;
	}

	void move(double dx, double dy)
	{
		cout << "X: " << this->x << "  dx: " << dx << "  Y: " << this->y << "  dy: " << dy << endl;

		this->x += dx;
		this->y += dy;
	}

	virtual void move()
	{

	}

};
#endif
