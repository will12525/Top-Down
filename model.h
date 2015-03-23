#ifndef _MODEL_H
#define _MODEL_H
#include "Tile.h"
#include <string>

enum Direction { UP, DOWN, LEFT, RIGHT, ESC, SPACE, RETURN};

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model(int width, int height);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Is the game over?
    bool gameOver();
    //which direction we are going
	
	void tick();
	
	
	void go(Direction d);
private:
	int xOffset;
	int yOffset;
	vector<Tile> tiles;
	
	void loadTiles(String path);
	
	
};

#endif