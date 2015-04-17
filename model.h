#include "Tile.h"
#include "Entity.h"
#include "PlayerEntity.cpp"
#include "Bullet.cpp"

#include <vector>
#include <string>
#include <map>
#include <ctime>

#ifndef _MODEL_H
#define _MODEL_H



using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT, ESCAPE, SPACE, RETURN};
enum State {START, LOAD, GAME, PLAY};

// The model manages the state of the game
class Model {
public:
		static Model* getInstance(){
		static Model* model=new Model(50, 50);
		return model;
	}

	// Destructor deletes all dynamically allocated stuff
  ~Model();
  // Is the game over?
  bool gameOver();
	void tick();
	void handleKey(map <int, bool> keys);

	int getXOffset();
	int getYOffset();
	void setXOffset(int x);
	void setYOffset(int x);
	vector<Tile> getTiles();
	vector<Entity> getEntities();
	State check;
	PlayerEntity getPlayer();

	vector<Bullet> bullets;


	void reset();

	void shoot();

private:
  // Constructor (instantiates object)
  Model(int width, int height);
	int xOffset;
	int yOffset;
	vector<Tile> tiles;
	vector<Entity> entities;


	void loadTiles(string path);
	PlayerEntity player;

	unsigned int lastShot = 0;




};
#endif
