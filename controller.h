#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "model.h"
#include "menu.h"
#include "view.h"


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
	#include "globalobjects.h"// weird this has to go here
};
#endif