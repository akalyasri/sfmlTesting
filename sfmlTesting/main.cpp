#include <SFML/Graphics.hpp>
#include "GameBoard.hpp"
#include <iostream>



int main()
{
    sf::RenderWindow window(sf::VideoMode(880, 880), "Game Board!");
    //sf::Style::Resize
    Board board(window);

 
    //will loop until you exit the program
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        

       // window.clear();
        board.drawBoard();
        board.placeShip("ship",'A',1,true);
      //  window.draw(text);
        window.display();
    }

    return 0;
}


