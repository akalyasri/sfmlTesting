#include "GameBoard.hpp"
#include <iostream>


Board::Board(sf::RenderWindow& window) : m_window(window) {

    // Set up the square shape
    m_square.setSize(sf::Vector2f(80.f, 80.f));

}

void Board::drawBoard() {

    sf::Color darkBlue1(12, 56, 97);
    sf::Color darkBlue2(8, 38, 66);
    sf::Color lightSeaBlue(135, 206, 250);
    sf::Color originalColor(255, 128, 64);


    sf::Font font;
   //font.loadFromFile("Fonts/arialbd.ttf");

   if (!font.loadFromFile("Fonts/arialbd.ttf")) {
        std::cout << "Error opening file" << std::endl;
    }

    sf::Text text;
    //("A", font, 500);
    text.setFont(font);
   // text.setString("HELLO");
    //text.setPosition(500, 400);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(24);
   // text.setStyle(sf::Text::Bold & sf::Text::Underlined);



    // Draw the board - checkers
    for (int y = 0; y < 11; y++) {

        for (int x = 0; x < 11; x++) {

            m_square.setPosition(x * 80.f, y * 80.f);

            //if ((x + y) % 2 == 0) {
                m_square.setOutlineThickness(5.f);
                m_square.setOutlineColor(sf::Color::White);
                m_square.setFillColor(lightSeaBlue);
            //}

          /*  else {
                m_square.setOutlineThickness(5.f);
                m_square.setOutlineColor(darkBlue1);
                m_square.setFillColor(darkBlue2);
            }*/

            m_window.draw(m_square);
         //   m_window.draw(text);

        }
    }


    // Draw white squares (first row and first column) for the labels
    m_square.setFillColor(sf::Color::White);

    for (int i = 0; i < 10; i++) {

        m_square.setPosition(i * 80.f + 80.f, 0);
        m_window.draw(m_square);

        m_square.setPosition(0, i * 80.f + 80.f);
        m_window.draw(m_square);
    }


    // Writing the labels
    char label = 'A';

    for (int i = 0; i < 10; i++) {

        text.setString(std::string(1, label));
        text.setPosition(i * 80.f + 80.f + 30.f, 5.f);

        m_window.draw(text);

        label++;

        text.setString(std::to_string(i));
        text.setPosition(5.f, i * 80.f + 80.f + 30.f);

        m_window.draw(text);
    }

  

}


