#include "controller.h"
#include "menu.h"
#include <map>

using namespace std;

Controller::Controller() {
  model = Model::getInstance();
  view = new View("Game", 1024, 768);
	menu = new Menu();
	startscreen =StartScreen::getInstance();
	loadscreen= LoadScreen::getInstance();
	ingamescreen = InGameScreen::getInstance();


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
  delete menu;
	delete startscreen;
	delete loadscreen;
	delete ingamescreen;
}

View* Controller::getView()
{
  return view;
}

/**
References:
https://wiki.libsdl.org/SDL_PollEvent
https://wiki.libsdl.org/SDL_Event
*/
void Controller::loop(){
  unsigned int lastTime = 0, currentTime;


  SDL_Event event;

  while(!model->gameOver())
	{
    currentTime = SDL_GetTicks();
    //Show the view
		if (model->check==PLAY){
    view->show(model);
		}
		else if (model->check==START){
		view->write(startscreen);
		}
    else if (model->check==LOAD){
		view->write(loadscreen);
		}
    else {
		view->write(ingamescreen);
		}

    if (SDL_PollEvent(&event) != 0)
		{
      switch (event.type)
			{
        case SDL_QUIT:
          return;
		  return;
          
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
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
              return;
            }
          }
          else if(model->check == LOAD)
          {
            loadscreen->navigate(direction[event.key.keysym.sym]);
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
              model->check = START;
            }
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
        case SDL_MOUSEBUTTONDOWN:
          break;
        default:
         break;
      }
    }

    //call the handlekey method every loop
    model->handleKey(keys);
  }

    // TODO: show something nice?
    view->show(model);
    SDL_Delay(3000);
}
