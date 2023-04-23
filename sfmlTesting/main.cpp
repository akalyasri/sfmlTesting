#include <SFML/Graphics.hpp>
#include "GameBoard.hpp"
#include <iostream>



int main()
{
    sf::RenderWindow window(sf::VideoMode(880*2, 880), "Game Board!");
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
        board.drawBoard(0,0);
        board.placeShip("Carrier",'B',5,0);
        board.placeShip("Cruiser", 'E', 0, 90);
      //  window.draw(text);
        window.display();

       

    }

    return 0;
}


