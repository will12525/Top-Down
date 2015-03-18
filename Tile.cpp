class Tile
{
public:
	Tile(int xcoord, int ycoord, int idnum)
	{
		x = xcoord;
		y = ycoord;
		id = idnum;
	}
	int getX()
	{
		return x;
	}
	
	int getY()
	{
		return y;
	}
	
	int getID()
	{
		return id;
	}
private:
	int x, y, id;

};