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

	void drawBoard();

	void placeShip(string shipName, char x, int y, int orientation);


private:

	sf::RenderWindow& m_window;

	sf::RectangleShape m_square;


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


