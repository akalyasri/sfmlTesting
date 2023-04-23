#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Board {

public:
	Board(sf::RenderWindow& window);

	void drawBoard(int startX, int startY);

	void placeShip(string shipName, char x, int y, int orientation);

	void placeBomb(char x, int y);

	bool checkHit(char x, int y); //include sound effects

	void placeExtras(string name, char x, int y);


private:

	sf::RenderWindow& m_window;

	sf::RectangleShape m_square;


	int locationX;
	int locationY;


};

















/*
class Board {

public: 

	Board(sf::RenderWindow& App);

	//Board(sf::RectangleShape& squareBoard);

	~Board();

	void restart();

	void drawBoard(sf::RectangleShape& squareBoard);

	int getWindowWidth();

	sf::Color &boardColor;

private:

	sf::RectangleShape& myBoard;
	sf::RenderWindow& myWindow;

	float windowHeight;
	float windowWidth;


};


*/


