#define _CRT_SECURE_NO_WARNINGS
#define SFML_NO_DEPRECATED_WARNINGS

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#define SPACE 10
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>


using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::toupper;
using std::getline;
using std::vector;
using std::put_time;
using std::localtime;

using std::stoi;


enum player
{
	PLAYER1,
	PLAYER2
};

enum state
{
	NSUNK = 0,
	SUNK = 1
};

enum choice
{
	NO,
	YES
};

enum printType
{
	BOARDPLAYER1,
	BOARDVIEWPLAYER1,
	BOARDPLAYER2,
	BOARDVIEWPLAYER2
};

enum hitType
{
	HIT,
	MISS
};


class Board {

public:
	Board(sf::RenderWindow& window);

	void drawBoard(int startX, int startY);

	void placeShip(string shipName, char x, int y, int orientation);

	void placeBomb(char x, int y);

	bool checkHit(char x, int y); //icnlude sound effects

	void placeExtras(string name, char x, int y);


private:

	sf::RenderWindow& m_window;

	sf::RectangleShape m_square;


	int locationX;
	int locationY;


};