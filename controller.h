#include "model.h"
#include "view.h"
#include "menu.h"

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
};
#endif
