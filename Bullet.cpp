#ifndef _BULLET_CPP
#define _BULLET_CPP

#include "Entity.h"
#include "Model.h"

using namespace std;

class Bullet: public Entity
{
public:
  Bullet()
  {
  //  this->x = Model::getInstance()->getPlayer().getX();
    //this->y = Model::getInstance()->getPlayer().getY();
    //this->rotation = Model::getInstance()->getPlayer().getRotation();
  }

  virtual void move()
  {

  }
};

#endif
