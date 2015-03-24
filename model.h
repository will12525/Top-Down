#ifndef _MODEL_H
#define _MODEL_H

#include "Tile.h"
#include <vector>
#include <string>

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT, ESCAPE, SPACE, RETURN};
enum State {MENU, GAME};

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model(int width, int height);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Is the game over?
    bool gameOver();
	void tick();
	void go(Direction d);
	
	int getXOffset();
	int getYOffset();
private:
	int xOffset;
	int yOffset;
	vector<Tile> tiles;
	
	void loadTiles(string path);
	
	
};
#endif
