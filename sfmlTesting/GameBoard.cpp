#include "GameBoard.hpp"
#include <iostream>


Board::Board(sf::RenderWindow& window) : m_window(window) {

    // Set up the square shape
    m_square.setSize(sf::Vector2f(80.f, 80.f));

}

void Board::drawBoard() {

    sf::Color darkBlue1(12, 56, 97);
    sf::Color darkBlue2(8, 38, 66);

    sf::Font font;
   //font.loadFromFile("Fonts/arialbd.ttf");

   if (!font.loadFromFile("Fonts/arialbd.ttf")) {
        std::cout << "Error opening file" << std::endl;
    }

    sf::Text text;
    //("A", font, 500);
    text.setFont(font);
    text.setString("HELLO");

    text.setPosition(500, 400);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold & sf::Text::Underlined);



    // Draw the board
    for (int y = 0; y < 11; y++) {

        for (int x = 0; x < 11; x++) {

            m_square.setPosition(x * 80.f, y * 80.f);

            if ((x + y) % 2 == 0) {
                m_square.setFillColor(darkBlue1);
            }

            else {
                m_square.setFillColor(darkBlue2);
            }

            //m_window.draw(m_square);
            m_window.draw(text);

        }
    }



}



/*
Board::Board(sf::RenderWindow& App) : myWindow(App) {


	//boardColor = sf::Color::Blue;



}




//Board::Board(sf::RectangleShape& squareBoard) : myBoard(squareBoard) {
//
//
//	for (int y = 0; y < 10; y++) {
//
//		for (int x = 0; x < 10; x++) {
//
//			squareBoard.setPosition(y * 80.f, x * 80.f);
//
//			if ((y + x) % 2 == 0) {
//				squareBoard.setFillColor(sf::Color::Black);
//
//			}
//			else {
//				squareBoard.setFillColor(sf::Color::Blue);
//			}
//
//
//		}
//
//
//	}
//
//
//}

// void Board::drawBoard(sf::RectangleShape &squareBoard) : myBoard(squareBoard) {
//
//
//	for (int y = 0; y < 10; y++) {
//
//		for (int x = 0; x < 10; x++) {
//			 
//			squareBoard.setPosition(y * 80.f, x * 80.f);
//
//			if ((y + x) % 2 == 0) {
//				squareBoard.setFillColor(sf::Color::Black);
//
//			}
//			else {
//				squareBoard.setFillColor(sf::Color::Blue);
//			}
//
//
//		}
//
//
//	}
//
//
//}


void Board::drawBoard(sf::RectangleShape& squareBoard) : myBoard(squareBoard) {
    for (int y = 1; y <= 10; y++) {
        for (int x = 1; x <= 10; x++) {
            squareBoard.setPosition(y * 80.f, x * 80.f);
            if ((y + x) % 2 == 0) {
                squareBoard.setFillColor(sf::Color::Black);
            }
            else {
                squareBoard.setFillColor(sf::Color::Blue);
            }
            // Draw the square with the specified position and color
           // App.draw(squareBoard);
        }
    }
}



*/