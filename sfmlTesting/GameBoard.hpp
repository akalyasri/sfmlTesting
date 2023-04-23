#pragma once


#include <SFML/Graphics.hpp>



class Board {

public:
	Board(sf::RenderWindow& window);

	void drawBoard();

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


