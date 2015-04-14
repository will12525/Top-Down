#include "model.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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
		label = "Start Saved File";
	}
	void doThing() {
			cout<<"here"<<endl;

		Model::getInstance()->check=PLAY;
	}
};

class NewGame : public MenuItem {
	public:
	NewGame() {
		label = "Make a New Game";
	}
	void doThing() {
		ofstream save_write;
		save_write.open("savefiles/game.txt");
			if (save_write.is_open())
			{
				cout<<"here";
				save_write<<300<<endl;
				save_write<<115<<endl;
				save_write<<0<<endl;
			}
			save_write.close();
		Model::getInstance()->reset();
		Model::getInstance()->check=PLAY;
	}
};

class SaveGame : public MenuItem {
	public:
	SaveGame() {
		label = "Save Game";
	}
	void doThing()
	{
		ofstream save_write;
		save_write.open("savefiles/game.txt");
			if (save_write.is_open())
			{
				cout<<"here";
				save_write<<Model::getInstance()->getPlayer().getX()<<endl;
				save_write<<Model::getInstance()->getPlayer().getY()<<endl;
				save_write<<Model::getInstance()->getPlayer().getRotation()<<endl;
		  }
	    save_write.close();
	}
};

class ExitGame : public MenuItem {
	public:
	ExitGame() {
		label = "Exit GAME";
	}
	void doThing() {
		cout<<"Exit game";
		Model::getInstance()->reset();
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
