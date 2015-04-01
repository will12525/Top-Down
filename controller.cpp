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

  keys[SDLK_UP] = false;
  keys[SDLK_DOWN] = false;
  keys[SDLK_LEFT] = false;
  keys[SDLK_RIGHT] = false;

  keys[SDLK_ESCAPE] = false;
  keys[SDLK_RETURN] = false;
  keys[SDLK_SPACE] = false;


  direction[SDLK_UP] = UP;
  direction[SDLK_DOWN] = DOWN;
  direction[SDLK_LEFT] = LEFT;
  direction[SDLK_RIGHT] = RIGHT;

  direction[SDLK_ESCAPE] = ESCAPE;
  direction[SDLK_SPACE] = SPACE;
  direction[SDLK_RETURN] = RETURN;
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
  unsigned int lastTime = 0, currentTime;

  SDL_Event event;

  while(!model->gameOver())
	{
    /*
    * add for tom: up, down, escape, enter for direction enum
    */
    currentTime = SDL_GetTicks();
    //Show the view
    view->show(model);

    if (SDL_PollEvent(&event) != 0)
		{
      switch (event.type)
			{
        case SDL_QUIT:
          //game over
          break;
        case SDL_KEYDOWN:
          //update key status
          if(model->check == PLAY)
          {
            keys[event.key.keysym.sym] = true;

            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
              model->check=GAME;
            }
          }
          else if(model->check == START)
          {
            startscreen->navigate(direction[event.key.keysym.sym]);
          }
          else if(model->check == LOAD)
          {
            loadscreen->navigate(direction[event.key.keysym.sym]);
          }
          else
          {
            ingamescreen->navigate(direction[event.key.keysym.sym]);
          }
          break;
        case SDL_KEYUP:
          //update key status again
          keys[event.key.keysym.sym] = false;
          break;
        default: break;
      }
    }

    //call the handlekey method every loop
    model->handleKey(keys);
  }

      /*
				case SDL_QUIT:
					return;
				case SDL_KEYDOWN:
					if (model->check == PLAY)
          {



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
            //break out of keydown
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
          */

    // TODO: show something nice?
    view->show(model);
    SDL_Delay(3000);
}
