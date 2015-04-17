#ifndef _ENEMYENTITY_CPP
#define _ENEMYENTITY_CPP
#include "Entity.h"
#include <string>
#include "PlayerEntity.cpp"
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265

using namespace std;

class EnemyEntity: public Entity
{
	public:
	int lastShot=0;
	EnemyEntity()
	{
		this->x=600;
		this->y=600;
		this->name="enemy";
		path="tileset/EnemyTank.png";
		dead=false;
		rotation=90;
	}
	EnemyEntity(double x, double y, string name)
	{
		this->x=x;
		this->y=y;
		this->name="enemy";
		path="tileset/EnemyTank.png";
		dead=false;
		rotation=0;
		
	}
	int getLastShot()
	{
		//cout<<"getting"<<endl;
		return lastShot;
	}
	void setShot(int shot)
	{
		cout<<"setting "<<shot<<endl;
		this->lastShot=shot;
	}
	void move(int speed)
	{
		
		
	//	this->x += speed*sin(rotation*(PI)/180);
		//this->y += speed*cos(rotation*(PI)/180);
		
		
		
	}
	void update(PlayerEntity player)
	{
		
		int modifier=0;
		if(player.getY()>y)
		{
				modifier=180;
		}
		double xDistance = player.getX()-x;
	
		double yDistance =player.getY()-y;
		
		double rate = (xDistance/yDistance);
		
		double angle = 180/(PI)* atan(rate)  +modifier;
		
		if(rotation<angle)
		{
			rotation++;
		}
		if(rotation>angle)
		{
			rotation--;
		}
		
		//rotation=angle;
		
		if(player.getX()<=x+300)
		{
			x--;
		}
		if(player.getX()>x-300)
		{
			x++;
		}
		
		if(player.getY()>y-300)
		{
			y++;
		}
		if(player.getY()<=y+300)
		{
			y--;
		}
		
	}

};
#endif