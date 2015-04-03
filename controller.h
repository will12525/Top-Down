#include "model.h"
#include "view.h"
#include "menu.h"

#ifndef _CONTROLLER_H
#define _CONTROLLER_H

// Handle input
class Controller {
public:
  static Controller * getInstance()
  {
    static Controller * controller = new Controller();
    return controller;
  }
    Controller();
    ~Controller();
    // Event loop
    void loop();

    View* getView();

private:
	StartScreen * startscreen;
	LoadScreen * loadscreen;
	InGameScreen * ingamescreen;
	Menu * menu;
	View * view;
	Model * model;
	Load*load;
	File *file;
	NewGame* newgame;
	SaveGame *savegame;
	ExitGame * exitgame;

  //key and bool map for key status
  map <SDL_Keycode, bool> keys;
  //key and direction for menu movement
  map <SDL_Keycode, Direction> direction;
};
#endif
