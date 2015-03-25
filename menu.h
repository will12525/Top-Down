using namespace std; 

class Menu{
	public: 
	// navigate any list
	
	virtual void up(){
		//move up
	}
	virtual void down(){
		//down
	}
	virtual void escape(){
		//escape
	}
	virtual void enter(){
		//enter
	}

	void Navigate (Direction d)
	{
		if(d == UP){
			up();
		}
		else if(d == DOWN){
			down();
		}
		else if(d == ESCAPE){
			escape();
		}
		else if(d == RETURN){
			enter();
		}
	}
	
};

class MenuItem {
	public:
	string label;
	virtual void doThing();
};

class Quit : public MenuItem {
	Quit() {
		label = "QUIT";
	}
	virtual void doThing() {
		//exit(0);
	}
};

class Load : public MenuItem {
	Load() {
		label = "LOAD";
	}
	virtual void doThing() {
		//exit(0);
	}
};

class File : public MenuItem {
	File() {
		label = "FILE";
	}
	virtual void doThing() {
		//exit(0);
	}
};

class NewGame : public MenuItem {
	NewGame() {
		label = "NEW GAME";
	}
	virtual void doThing() {
		//exit(0);
	}
};

class SaveGame : public MenuItem {
	SaveGame() {
		label = "SAVE GAME";
	}
	virtual void doThing() {
		//exit(0);
	}
};

class ExitGame : public MenuItem {
	ExitGame() {
		label = "Exit GAME";
	}
	virtual void doThing() {
		//exit(0);
	}
};




class StartScreen: public Menu{
	StartScreen(){
		start [0]=load;
		start [1]=quit;
	}
	public:
	void loadfun(){
		//switch to load menu
	}
	void quitfun(){
		//exit game;
	}
	MenuItem load;
	MenuItem quit;
	MenuItem start[2];
};

class LoadScreen: public Menu{
	LoadScreen(){
		start [0]=file;
		start [1]=new_game;
	}
	public:
	void filefun(){
		//switch state from MENU to GAME
	}
	void new_gamefun(){
		//newgame begins
	}
	
	MenuItem file;
	MenuItem new_game;
	MenuItem start[2];
};

class InGameScreen: public Menu{
	InGameScreen(){
		ingame[0]=save;
		ingame[1]=exit;
	}
	public:
	void savefun(){
		
	}
	void exitfun(){
		
	}
	MenuItem save;
	MenuItem exit;
	MenuItem ingame[2];
};











