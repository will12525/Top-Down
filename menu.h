#include "model.h"
#include <iostream>

#ifndef _MENU_H
#define _MENU_H


using namespace std; 


class Menu{
	public: 
	// navigate any list
	
	virtual void up(){
		//increment the location 
	}
	virtual void down(){
		//decrement the location 
	}
	virtual void enter(){
		cout << "enter stuff: Return" << endl;
		//run code at corrent location 
		Model::getInstance()->check=PLAY;
	}

	void navigate (Direction d)
	{
		if(d == UP){
			//up();
			cout << "Debug: Up" << endl;
		}
		else if(d == DOWN){
			cout << "Debug: Down" << endl;
		}
		else if(d == RETURN){
			cout << "Debug: Return" << endl;
			enter();
		}
	}
	
};

class MenuItem {
	public:
	MenuItem(){}
	~MenuItem(){}
	string label;
	virtual void doThing(){}
};

class Load : public MenuItem {
	public:
	Load() {
		label = "LOAD";
	}
	virtual void doThing() {
		//exit(0);
	}
};

class File : public MenuItem {
	public:
	File() {
		label = "FILE";
	}
	virtual void doThing() {
		//exit(0);
	}
};

class NewGame : public MenuItem {
	public:
	NewGame() {
		label = "NEW GAME";
	}
	virtual void doThing() {
		//exit(0);
	}
};

class SaveGame : public MenuItem {
	public:
	SaveGame() {
		label = "SAVE GAME";
	}
	virtual void doThing() {
		//exit(0);
	}
};

class ExitGame : public MenuItem {
	public:
	ExitGame() {
		label = "Exit GAME";
	}
	virtual void doThing() {
	}
};






class StartScreen: public Menu{
	public:
	StartScreen(){
		start [0]=load;
	}
	void loadfun(){
		//switch to load menu
	}
	Load load;
	MenuItem start[2];
};

class LoadScreen: public Menu{
	public:
	LoadScreen(){
		start [0]=file;
		start [1]=new_game;
	}
	void filefun(){
		//switch state from MENU to GAME
	}
	void new_gamefun(){
		//newgame begins
	}
	
	File file;
	NewGame new_game;
	MenuItem start[2];
};

class InGameScreen: public Menu{
	public:
	InGameScreen(){
		ingame[0]=save;
		ingame[1]=exit;
	}
	void savefun(){
		
	}
	void exitfun(){
		
	}
	SaveGame save;
	ExitGame exit;
	MenuItem ingame[2];
};

#endif









