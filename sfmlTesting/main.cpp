#include <SFML/Graphics.hpp>
#include "GameBoard.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(880, 880), "Game Board!",sf::Style::Resize);

    Board board(window);

   // sf::RectangleShape squareBoard(sf::Vector2f(80.f, 80.f));

    /*sf::CircleShape shape(100.f);

    shape.setFillColor(sf::Color::Green);*/

    //reduces CPU usuage
    //window.setFramerateLimit(30);

    //will loop until you exit the program
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        board.drawBoard();
        window.display();
    }

    return 0;
}