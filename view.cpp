#include "view.h"
#include "view.h"
#include <iostream>
#include "Tile.h"


#include <string>
#include "Entity.h"

using namespace std;

// Initialize SDL
View::View(string title, int width, int height) {
    fail = false;
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
        fail = true;
        return;
    }
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fail = true;
        return;
    }
    // Get the screen
    screen = SDL_GetWindowSurface(window);
    //Initialize JPEG and PNG loading
    if( !( IMG_Init( IMG_INIT_JPG|IMG_INIT_PNG ) & (IMG_INIT_JPG|IMG_INIT_PNG) ) ) {
        fail = true;
        return;
    }
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        fail = true;
        return;
    }

    // Initialize True type fonts
    if( TTF_Init() == -1 ) {
        return;
    }
    // Load assets
//    snake = load("assets/snake.png");
//    music = Mix_LoadMUS("assets/2Inventions_-_Johaness_Gilther_-_Don_t_leave_me.mp3");
//    if (music != NULL) {
//       Mix_PlayMusic( music, -1 );
//    }
//    food = Mix_LoadWAV("assets/yummy.wav");
    font = TTF_OpenFont( "assets/LiberationSans-Regular.ttf", 24 );
	  text_color={255,255,255};
	  text = TTF_RenderText_Solid(font,"Menu, comming soon. Press enter to go to the game, and Esc for the game to come back here", text_color);

}

View::~View() {
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

/**
 *  Load an image from a file to a SDL_Surface
 */
SDL_Surface* View::load(string path) {
    // Load image
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ) {
        return NULL;
    }
    // Convert surface to screen format
    optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, 0 );

    // Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

    return optimizedSurface;
}

void View::show(Model * model) {
	vector<Tile> tiles = model->getTiles();
	vector<Entity> entities = model->getEntities();
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));

	SDL_Surface * tile1 = load("tileset/1.png");
	

	for(int i = 0; i < tiles.size(); i++)
	{
		Tile t = tiles[i];
		//render tile

		SDL_Rect source;
		SDL_Rect destination;
		source.x = 0;
		source.y = 0;
		source.w = 64;
		source.h = 64;
		destination.x = t.getX() * 64 + model->getXOffset();
		destination.y = t.getY() * 64 + model->getYOffset();
		SDL_BlitSurface( tile1, &source, screen, &destination );
	}
	
	for(int i = 0;i<entities.size();i++)
	{
		Entity ent = entities[i];
		
		SDL_Surface * image = load(ent.getPath());
		//SDL_Surface * rotation = rotozoomSurface(image,5,1,1);
		//image=rotation;
		//SDL_FreeSurface(rotation);
		SDL_Rect source;
		SDL_Rect destination;
		source.x=0;
		source.y=0;
		source.w=image->w;
		source.h=image->h;

		
		
		destination.x=ent.getX();
		destination.y=ent.getY();
		SDL_BlitSurface(image,&source,screen,&destination);
	}

    SDL_UpdateWindowSurface(window);
}

void View::write(Menu * menu){
	// Clear the screen
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));

    text = TTF_RenderText_Solid(font,"Menu, comming soon. Press enter to go to the game, and Esc for the game to come back here", text_color);

    SDL_BlitSurface(text, NULL, screen, NULL);

  //rewrite text// this can be done better i think

    string s = menu->storage[menu->position].label;
    const char *pchar = s.c_str();
    text=TTF_RenderText_Solid(font,pchar, text_color);

	//aply text

    SDL_Rect end;
    end.x = 0;
    end.y = 64;
    SDL_BlitSurface( text, NULL, screen, &end );
  	SDL_UpdateWindowSurface(window);
}
