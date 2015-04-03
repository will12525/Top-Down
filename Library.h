#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

#ifndef _LIBRARY_H
#define _LIBRARY_H

using namespace std;

class Library
{
public:
  static Library * getInstance()
  {
    static Library * library = new Library();
    return library;
  }
  SDL_Surface* getImage(string path);
private:
  map<string, SDL_Surface*> images;
};

#endif
