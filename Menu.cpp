#include "menu.h"
using namespace std;
	Menu::Menu(){
		storage.resize(2);

	}
	Menu::~Menu(){}
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
			if (StartScreen::getInstance()->position<0){
				StartScreen::getInstance()->position++;
			}
		}
		else if (Model::getInstance()->check==LOAD){
			if (LoadScreen::getInstance()->position<1){
				LoadScreen::getInstance()->position++;
			}
		}
		else{
			if (InGameScreen::getInstance()->position<1){
				InGameScreen::getInstance()->position++;
			}
		}
	}
	void Menu::enter(){
		if (Model::getInstance()->check==START){
				StartScreen::getInstance()->load.doThing();
		}
		else if (Model::getInstance()->check==LOAD){
			if (position== 0){
				LoadScreen::getInstance()->file.doThing();
			}
			else{
				LoadScreen::getInstance()->new_game.doThing();
			}
		}
		else{
			if (position== 0){
				InGameScreen::getInstance()->save.doThing();
			}
			else{
				InGameScreen::getInstance()->exit.doThing();
			}
		}

	}
	void Menu::navigate (Direction d){
		if(d == UP){
			this->up();
		}
		else if(d == DOWN){
			this->down();
		}
		else if(d == RETURN){
			this->enter();
		}
	}
