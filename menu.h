#include "model.h"
#include <iostream>

#ifndef _MENU_H
#define _MENU_H


using namespace std;


class Menu{
	public:
	// navigate any list


	void up();
	void down();
	void enter();

	void navigate (Direction d)
	{
		if(d == UP){
			cout << "Debug: Up" << endl;
			up();
		}
		else if(d == DOWN){
			cout << "Debug: Down" << endl;
			down();
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
		Model::getInstance()->check=LOAD;
	}
};

class File : public MenuItem {
	public:
	File() {
		label = "FILE";
	}
	virtual void doThing() {
		Model::getInstance()->check=PLAY;
	}
};

class NewGame : public MenuItem {
	public:
	NewGame() {
		label = "NEW GAME";
	}
	virtual void doThing() {
		//start a new file
	}
};

class SaveGame : public MenuItem {
	public:
	SaveGame() {
		label = "SAVE GAME";
	}
	virtual void doThing() {
		//write current position to text file
	}
};

class ExitGame : public MenuItem {
	public:
	ExitGame() {
		label = "Exit GAME";
	}
	virtual void doThing() {
		Model::getInstance()->check=START;
	}
};


class StartScreen: public Menu{
	public:
		static StartScreen* getInstance(){
		static StartScreen* startscreen= new StartScreen;
		return startscreen;
	}

	StartScreen(){
		start [0]=load;
		position=0;
	}
	~StartScreen(){}
	void loadfun(){
		load.doThing();
	}
	Load load;
	MenuItem start[1];
	int position;
};

class LoadScreen: public Menu{
	public:
		static LoadScreen* getInstance(){
		static LoadScreen* loadscreen= new LoadScreen;
		return loadscreen;
	}

	LoadScreen(){
		start [0]=file;
		start [1]=new_game;
		position=0;
	}
	~LoadScreen(){}
	void filefun(){
		file.doThing();
	}
	void new_gamefun(){
		new_game.doThing();
	}

	File file;
	NewGame new_game;
	MenuItem start[2];
	int position;
};

class InGameScreen: public Menu{
	public:
		static InGameScreen* getInstance(){
		static InGameScreen*ingamescreen= new InGameScreen;
		return ingamescreen;
	}
	InGameScreen(){
		ingame[0]=save;
		ingame[1]=exit;
		position=0;
	}
	~InGameScreen(){}

	void savefun(){
		save.doThing();
	}
	void exitfun(){
		exit.doThing();
	}
	SaveGame save;
	ExitGame exit;
	MenuItem ingame[2];
	int position;
};


//////////////////////////////

void Menu::up(){
	//if position value is greater then zero position--
	if (Model::getInstance()->check==START){
		if (StartScreen::getInstance()->position>0){
			StartScreen::getInstance()->position--;
		}
	}
	else if (Model::getInstance()->check==LOAD){
		if (LoadScreen::getInstance()->position>0){
			LoadScreen::getInstance()->position--;
		}
	}
	else{
		if (InGameScreen::getInstance()->position>0){
			InGameScreen::getInstance()->position--;
		}
	}

}
void Menu::down(){
	//if position value is less then array size for
	//current menu,position++
	if (Model::getInstance()->check==START){
		if (StartScreen::getInstance()->position<1){
			StartScreen::getInstance()->position++;
		}
	}
	else if (Model::getInstance()->check==LOAD){
		if (LoadScreen::getInstance()->position<2){
			LoadScreen::getInstance()->position++;
		}
	}
	else{
		if (InGameScreen::getInstance()->position<2){
			InGameScreen::getInstance()->position++;
		}
	}
}
void Menu::enter(){
	cout << "enter stuff: Return" << endl;
	Model::getInstance()->check=PLAY;
}





#endif
