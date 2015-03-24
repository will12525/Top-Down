#include <list>
using namespace std;

struct item{
	//
	//
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
		escape
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
		
	}
	public:
	void start(){
		
	}
	void load(){
		
	}

};

class InGame: public Menu{
	InGame(){
		
	}
	public:
	void quit(){
		
	}
	void save(){
		
	}
	void items(){
		
	}
};











