#include "header.h"

class ship
{
public:
	ship()
	{
		player = -1;
		hp = 0;
		identification = NULL;
		hit = 0;
		sunk = 0;
	}

	ship(int uPlayer, int uHP, char uIdentification, int uHit, int uSunk)
	{
		player = uPlayer;
		hp = uHP;
		identification = uIdentification;
		hit = uHit;
		sunk = uSunk;
	}
	~ship()
	{

	}
	void setPlayer(int uPlayer)
	{
		player = uPlayer;
	}
	void setHP(int uHP)
	{
		hp = uHP;
	}
	void setIdentification(char uIdetification)
	{
		identification = uIdetification;
	}
	void setHit(int uHit)
	{
		hit = uHit;
	}
	void setSunk(int uSunk)
	{
		sunk = uSunk;
	}

	int getPlayer()
	{
		return player;
	}
	int getHP()
	{
		return hp;
	}
	char getIdentification()
	{
		return identification;
	}
	int getHit()
	{
		return hit;
	}
	int getSunk()
	{
		return sunk;
	}



	void setX(int uX)
	{
		x = uX;
	}
	void setY(int uY)
	{
		y = uY;
	}
	void setOrientation(int uRotation)
	{
		orintation = uRotation;
	}

	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getOrientation()
	{
		return orintation;
	}



private:
	int player;
	int hp;
	char identification;
	int hit;
	int sunk;

	int x = 0;
	int y = 0;
	int orintation = 0;
};

class fleet
{
public:
	fleet()
	{
		carrier = new ship(PLAYER1, 5, 'p', 0, NSUNK);
		battleship = new ship(PLAYER1, 4, 'b', 0, NSUNK);
		cruiser = new ship(PLAYER1, 3, 'c', 0, NSUNK);
		submarine = new ship(PLAYER1, 3, 's', 0, NSUNK);
		destroyer = new ship(PLAYER1, 2, 'd', 0, NSUNK);

	}

	ship* carrier;
	ship* battleship;
	ship* cruiser;
	ship* submarine;
	ship* destroyer;

};

class logBook //keeps track of shots fired
{

public:
	vector<int> x;
	vector<int> y;
};