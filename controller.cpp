#include "controller.h"
#include <map>

using namespace std;

Controller::Controller() {
    model = Model::getInstance();
    view = new View("Game", 1024, 768);
	menu = new Menu();
	startscreen =new StartScreen();
	loadscreen= new LoadScreen();
	ingamescreen = new InGameScreen();
	load=new Load();
	file=new File();
	newgame=new NewGame();
	savegame=new SaveGame();
	exitgame=new ExitGame();
}

Controller::~Controller() {
    delete model;
    delete view;
	delete startscreen;
	delete loadscreen;
	delete ingamescreen;
	delete newgame;
	delete savegame;
	delete exitgame;
	delete load;
	delete file;
}
/**
References:
https://wiki.libsdl.org/SDL_PollEvent
https://wiki.libsdl.org/SDL_Event
*/
void Controller::loop() {
    SDL_Event e;
    unsigned int lastTime = 0, currentTime;
    std::map<SDL_Keycode, Direction> direction;
    direction[SDLK_UP] = UP;
    direction[SDLK_DOWN] = DOWN;
    direction[SDLK_LEFT] = LEFT;
    direction[SDLK_RIGHT] = RIGHT;
	direction[SDLK_ESCAPE] = ESCAPE;
	direction[SDLK_SPACE] = SPACE;
	direction[SDLK_RETURN] = RETURN;
	

	


    while(!model->gameOver())
	{
        currentTime = SDL_GetTicks();
        // Do stuff here to animate as necessary
        view->show(model);
		
        if (SDL_PollEvent(&e) != 0)
		{
            switch (e.type)
			{
				case SDL_QUIT:
					return;
				case SDL_KEYDOWN:
					if (model->check == PLAY){
						switch(e.key.keysym.sym)
						{
							case SDLK_DOWN:
							case SDLK_UP:
							case SDLK_LEFT:
							case SDLK_RIGHT:
							case SDLK_RETURN:
							case SDLK_SPACE:
								model->go(direction[e.key.keysym.sym]);
								break;
							case SDLK_ESCAPE:
								model->check=GAME;
								break;
						}
						break;
					}
					else if(model->check == START)
					{
						switch(e.key.keysym.sym)
						{
							case SDLK_DOWN:
							case SDLK_UP:
							case SDLK_RETURN:
								startscreen->navigate(direction[e.key.keysym.sym]);
								break;
							case SDLK_ESCAPE:
								return;
								break;
						}  
						break;
					}
					else if(model->check == LOAD)
					{
						switch(e.key.keysym.sym)
						{
							case SDLK_DOWN:
							case SDLK_UP:
							case SDLK_RETURN:
								loadscreen->navigate(direction[e.key.keysym.sym]);
								break;
							case SDLK_ESCAPE:
								model->check=START;
								break;
						}  
						break;
					}
					else if(model->check == GAME)
					{
						switch(e.key.keysym.sym)
						{
							case SDLK_DOWN:
							case SDLK_UP:
							case SDLK_RETURN:
								loadscreen->navigate(direction[e.key.keysym.sym]);
								break;
						}  
						break;
					}
			
				case SDL_MOUSEBUTTONDOWN: //SDL_GetMouseState
					break;
				default:
					break;
            }
          
        }
    
	}
    // TODO: show something nice?
    view->show(model);
    SDL_Delay(3000);

}
