#include <list>
using namespace std;

enum 

struct item{
	string label;
	void (*function)();//function pointer
};

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
		else if(d == ENTER){
			enter();
		}
	}
	
};



class Start: public Menu{
	Start(){
		item start[]
		//initialize to array location of zero
	}
};

class InGame: public Menu{
	InGame(){
		// array of items 
	}
};











