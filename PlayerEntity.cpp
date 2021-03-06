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
		ifstream save_read;
		save_read.open("savefiles/game.txt");
			if (save_read.is_open()){
				int count=1;
				string line;
				int coord;
				while ( getline (save_read,line)){
					coord = std::stoi(line);
					if (count== 1){
						this->x=coord;
					}
					else if (count==2) {
						this->y=coord;
					}
					else if (count==3){
						cout<<coord;
						this->rotation=coord;
					}
					count++;
				}
			save_read.close();
			}
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
		direction *=-1;
		this->x +=  direction * sin(rotation*(PI)/180);
		this->y +=  direction * cos(rotation*(PI)/180);
	}


};
#endif
