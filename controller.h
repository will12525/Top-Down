#include "model.h"
#include "menu.h"
#include "view.h"


#ifndef _CONTROLLER_H
#define _CONTROLLER_H

// Handle input
class Controller {
public:
    Controller();
    ~Controller();
    // Event loop
    void loop();

private:
	StartScreen * startscreen;
	LoadScreen * loadscreen;
	InGameScreen * ingamescreen;
	Menu * menu;
    View * view;
	Model * model;
	Load*load;
	File *file;
	NewGame*newgame;
	SaveGame *savegame;
	ExitGame * exitgame;

  //key and bool map for key status
  map <SDL_Keycode, bool> keys;
  //key and direction for menu movement
  map <SDL_Keycode, Direction> direction;
};
#endif
