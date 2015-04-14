#include "view.h"
#include "view.h"
#include <iostream>
#include "Tile.h"

#include "SDL2_rotozoom.h"
#include <SDL2/SDL.h>
#include <string>
#include "Entity.h"
#include "library.h"

using namespace std;

// Initialize SDL
View::View(string title, int width, int height) {
	this->width=width;
	this->height=height;
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
	int pX=(model->getPlayer().getX());
	int pY=(model->getPlayer().getY());

	if(pX<=width/2)
	{
		xOff=0;
	}
	else{
		xOff=(pX)-(width/2);
	}
	if(pY<=height/2)
	{
		yOff=0;
	}
	else{
		yOff=(pY)-(height/2);
	}



	vector<Tile> tiles = model->getTiles();
	vector<Entity> entities = model->getEntities();
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));

	//SDL_Surface * tile1 = load("tileset/1.png");

	for(int i = 0; i < tiles.size(); i++)
	{
		Tile t = tiles[i];
		//render tile
    SDL_Surface * image = Library::getInstance()->getImage(t.getPath());
		SDL_Rect source;
		SDL_Rect destination;
		source.x = 0;
		source.y = 0;
		source.w = 64;
		source.h = 64;
		destination.x = (t.getX() * 64)-xOff;
		destination.y = (t.getY() * 64)-yOff;
		SDL_BlitSurface( image, &source, screen, &destination );

	}

	//draw player
	SDL_Surface* image = load(model->getPlayer().getPath());
	SDL_Surface * rotation = rotozoomSurface(image,model->getPlayer().getRotation(),1,1);
	image=rotation;
	SDL_Rect source, destination;
	source.x = 0;
	source.y = 0;
	source.w = image->w;
	source.h = image->h;

	model->getPlayer().setImageOffset((image->w)/2,(image->h)/2);

	destination.x = ((model->getPlayer().getX())-((image->w)/2))-xOff;
	destination.y = ((model->getPlayer().getY())-((image->h)/2))-yOff;
	SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
	SDL_BlitSurface(image, &source, screen, &destination);


	cout << "Rendering " << entities.size() << " entities" << endl;
	for(int i = 0;i<entities.size();i++)
	{
		Entity ent = entities[i];

		//move the entity before we draw
		ent.move(1);

		SDL_Surface * image = load(ent.getPath());

		SDL_Surface * rotation = rotozoomSurface(image,ent.getRotation(),1,1);
		image=rotation;

		SDL_Rect source;
		SDL_Rect destination;
		source.x=0;
		source.y=0;
		source.w=image->w;
		source.h=image->h;



		destination.x=ent.getX()-((image->w)/2)-xOff;
		destination.y=ent.getY()-((image->h)/2)-yOff;
		SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
		SDL_BlitSurface(image,&source,screen,&destination);

		//SDL_FreeSurface(rotation);
	}

    SDL_UpdateWindowSurface(window);
}


void View::write(Menu * menu){
	// Clear the screen
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));

    text = TTF_RenderText_Solid(font,"Menu, comming soon. Press enter to go to the game, and Esc for the game to come back here", text_color);
    SDL_BlitSurface(text, NULL, screen, NULL);

    for (int i=0; i <2; i++){
    subwrite(menu, i);
    pointwrite(menu);
    }
    SDL_UpdateWindowSurface(window);
}

void View::subwrite(Menu * menu, int offset){
  //rewrite text// this can be done better i think
    string s = menu->storage[offset].label;
    offset=(offset*64)+64;
    const char *pchar = s.c_str();
    text=TTF_RenderText_Solid(font,pchar, text_color);
	//aply text
    SDL_Rect end;
    end.x = 20;
    end.y = offset;
    SDL_BlitSurface( text, NULL, screen, &end );

}
void View::pointwrite(Menu * menu){
  //rewrite text// this can be done better i think
    SDL_Surface * s = SDL_CreateRGBSurface(0, 10, 10, 32, 0, 0, 0, 0);
    SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 255, 0, 0));
    int offset=((menu->position)*64)+70;
    SDL_Rect end;
    end.x = 6;
    end.y = offset;
    SDL_BlitSurface( s, NULL, screen, &end );

}
