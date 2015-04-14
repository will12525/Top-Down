#ifndef _BULLET_CPP
#define _BULLET_CPP

#include "Entity.h"

using namespace std;

class Bullet: public Entity
{
public:

  Bullet(int x, int y, string name)
  : Entity(x, y, name)
  {
    path = "tileset/bullet.png";
  }


  virtual void move()
  {

  }
};

#endif
