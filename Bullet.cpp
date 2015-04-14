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
  : Entity(x, y, name, speed)
  {
    path = "tileset/bullet.png";
  }


  virtual void move(int direction)
  {
    cout << "bullet move " << endl;

    this->x += direction * speed * sin(rotation*(PI)/180);
		this->y += direction * speed * cos(rotation*(PI)/180);
  }
};

#endif
