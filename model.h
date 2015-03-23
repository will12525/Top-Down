#ifndef _MODEL_H
#define _MODEL_H

<<<<<<< HEAD
enum Direction { UP, DOWN, LEFT, RIGHT, ESC, SPACE, RETURN};
enum State {MENU, GAME};
=======
#include "Tile.h"
#include <string>
#include <vector>

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT, ESCAPE, SPACE, RETURN};
>>>>>>> fc76d69a88550521582a82b9babe6ebd142b9bbe

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
	
	void loadTiles(string path);
	
	
};
#endif
