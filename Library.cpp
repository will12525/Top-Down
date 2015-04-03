#include "library.h"
#include "view.h"
#include "controller.h"

using namespace std;

SDL_Surface* Library::getImage(string path)
{
  if(!images.count(path))
  {
    //map does not contain key
    images[path] = Controller::getInstance()->getView()->load(path);
    return images[path];
  }
  else
  {
    return images[path];
  }
}
