#ifndef _MODEL_H
#define _MODEL_H

enum Direction { UP, DOWN, LEFT, RIGHT, ESC, SPACE, RETURN};

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Is the game over?
    bool gameOver();
    //which direction we are going
	void go(Direction d);
private:
	int xOffset;
	int yOffset;
};

#endif