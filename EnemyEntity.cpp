#ifndef _ENEMYENTITY_CPP
#define _ENEMYENTITY_CPP
#include "Entity.h"
#include <string>

#define PI 3.14159265

using namespace std;

class EnemyEntity: public Entity
{
	public:
	
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
		rotation=90;
		
	}
	void move(int speed)
	{
		
		cout<<this->x<<endl;
		this->x += speed*sin(rotation*(PI)/180);
		this->y += speed*cos(rotation*(PI)/180);
		
		cout<<this->x<<endl;
		
	}
	


	
	
};
#endif