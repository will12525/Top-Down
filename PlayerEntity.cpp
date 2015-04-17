#ifndef _PLAYERENTITY_CPP
#define _PLAYERENTITY_CPP

#include "Entity.h"
#include <string>
#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace std;

class PlayerEntity: public Entity
{
public:
	PlayerEntity()
	{
		this->x=487;
		this->y=359;
		this->name="will";
		path="tileset/PlayerTank.png";
		dead=false;
		rotation=0;
		speed = 5;
	}
	PlayerEntity(double x,double y,string name)
	{
		this->x=x;
		this->y=y;
		this->name=name;
		path="tileset/PlayerTank.png";
		dead=false;
		rotation=0;
		speed = 5;
	}

	void move(int direction)
	{
	//	cout << "playerentity move" << endl;
		//because its backwards
		direction *= -1;
		this->x += direction * speed * sin(rotation*(PI)/180);
		this->y += direction * speed * cos(rotation*(PI)/180);
	}

};
#endif
