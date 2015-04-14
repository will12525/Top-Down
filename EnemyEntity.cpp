#ifndef _ENEMYENTITY_CPP
#define _ENEMYENTITY_CPP
#include "Entity.h"
#include <string>

using namespace std;

class EnemyEntity: public Entity
{
	public: 
	EnemyEntity()
	{
		
	}
	EnemyEntity(double x, double y, string name)
	{
		this->x=600;
		this->y=600;
		this->name="enemy";
		path="tileset/EnemyTank.png";
		dead=false;
		rotation=0;
	}
	
	
};
#endif