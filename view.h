
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include "SDL2_rotozoom.h"
#include "model.h"
#include <map>
#include <string>
#include "menu.h"
#ifndef _VIEW_H
#define _VIEW_H


// Show (output) the state of the model
class View {
public:

    View(std::string title, int width, int height);
    ~View();
    // Print out the visible stuff in the grid
    void show(Model * model);
	  void write(Menu * menu);
    SDL_Surface* load(string path);
	void setOffset(int xOff,int yOff);
private:
    void subwrite(Menu * menu, int offset);
    void pointwrite(Menu * menu);
    SDL_Window* window;
    SDL_Surface* screen;
    bool fail;
	  SDL_Surface* text;
	  SDL_Color text_color;
    Mix_Music * music;
    Mix_Chunk * shoot;
    TTF_Font * font;
	int width,height,xOff,yOff;
};
#endif
