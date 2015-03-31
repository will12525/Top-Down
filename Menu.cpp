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
		cout<< position;
		if (Model::getInstance()->check==START){
				StartScreen::getInstance()->storage[position];
		}
		else if (Model::getInstance()->check==LOAD){
			//	LoadScreen::getInstance()->storage[position].doThing;
		}
		else{
		//		InGameScreen::getInstance()->storage[position].doThing;
		}

	}
	void Menu::navigate (Direction d){
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
