#include "model.h"
#include <iostream>
#include <vector>

#ifndef _MENU_H
#define _MENU_H


using namespace std;

class MenuItem {
	public:
	MenuItem(){}
	~MenuItem(){}
	string label;
	virtual void doThing(){}
};


class Menu{
	public:
	// navigate any list
	Menu();
	~Menu();
	void up();
	void down();
	void enter();
	void navigate(Direction d);
	int position;
	vector<MenuItem> storage ;
};


class Load : public MenuItem {
	public:
	Load() {
		label = "Load";
	}
	virtual void doThing() {
		cout<<"change start to load";
		Model::getInstance()->check=LOAD;
	}
};

class File : public MenuItem {
	public:
	File() {
		label = "File";
	}
	void doThing() {
		Model::getInstance()->check=PLAY;
	}
};

class NewGame : public MenuItem {
	public:
	NewGame() {
		label = "New Game";
	}
	void doThing() {
		//start a new file
	}
};

class SaveGame : public MenuItem {
	public:
	SaveGame() {
		label = "Save Game";
	}
	void doThing() {
		cout<<"savegame"<<endl;
	}
};

class ExitGame : public MenuItem {
	public:
	ExitGame() {
		label = "Exit GAME";
	}
	void doThing() {
		cout<<"Exit game";
		Model::getInstance()->check=START;
	}
};




class StartScreen: public Menu{
	public:
		static StartScreen* getInstance(){
		static StartScreen* startscreen= new StartScreen();
		return startscreen;
	}
	~StartScreen(){}
	Load load;

private:
	StartScreen(){
		storage[0]=load;
	}
};

class LoadScreen: public Menu{
	public:
		static LoadScreen* getInstance(){
		static LoadScreen* loadscreen= new LoadScreen();
		return loadscreen;
	}
	~LoadScreen(){}
	File file;
	NewGame new_game;

private:
	LoadScreen(){
		storage[0]=file;
		storage[1]=new_game;
	}
};

class InGameScreen: public Menu{
	public:
		static InGameScreen* getInstance(){
		static InGameScreen*ingamescreen= new InGameScreen();
		return ingamescreen;
	}
	~InGameScreen(){}
	SaveGame save;
	ExitGame exit;

private:
	InGameScreen(){
		storage[0]=save;
		storage[1]=exit;
	}
};

#endif
