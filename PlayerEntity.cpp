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
	//PlayerEntity(double x,double y,string name)
	{
		this->x=487;
		this->y=359;
		this->name="will";
		path="tileset/PlayerTank.png";
		dead=false;
		rotation=0;

	}

	void move(int speed)
	{
		//cout << "X: " << this->x << "  dx: " << dx << "  Y: " << this->y << "  dy: " << dy << endl;
		cout<<rotation<<endl;
		this->x += speed*sin(rotation*(PI)/180);
		this->y += speed*cos(rotation*(PI)/180);
	}

	virtual void move()
	{

	}

};
#endif
