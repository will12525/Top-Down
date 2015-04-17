#ifndef _BULLET_CPP
#define _BULLET_CPP

#include "Entity.h"
#include <math.h>
#include <iostream>

using namespace std;

class Bullet: public Entity
{
public:

  Bullet(int x, int y, string name, double speed)
  //: Entity(x, y, name, speed)
  {
    path = "tileset/bullet.png";
    this->x = x;
    this->y = y;
    this->speed = speed;
	dead=false;
  }


  void move(int direction)
  {
    //cout << "                                 bullet move1 " << speed << " " << x << " " << y << " " << direction << endl;
    //cout << "x increase: " << (direction * speed * sin(rotation*(PI)/180)) << endl;
    //cout << "y increase: " << (direction * speed * cos(rotation*(PI)/180)) << endl;
    this->x += direction * speed * sin(rotation*(PI)/180);
		this->y += direction * speed * cos(rotation*(PI)/180);

    //cout << "                                 bullet move2 " << speed << " " << x << " " << y << " " << direction << endl;

  }
};

#endif
