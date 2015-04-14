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

	}
	PlayerEntity(double x,double y,string name)
	{
		this->x=x;
		this->y=y;
		this->name=name;
		path="tileset/PlayerTank.png";
		dead=false;
		rotation=0;
	}

	void move(int speed)
	{
		//cout << "X: " << this->x << "  dx: " << dx << "  Y: " << this->y << "  dy: " << dy << endl;
	//cout<<rotation<<endl;
		this->x += speed*sin(rotation*(PI)/180);
		this->y += speed*cos(rotation*(PI)/180);
	}

	virtual void move()
	{

	}


};
#endif
