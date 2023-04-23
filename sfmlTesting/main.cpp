#include <SFML/Graphics.hpp>
#include "GameBoard.hpp"
#include <iostream>


//#if 0

int main()
{
    sf::RenderWindow window(sf::VideoMode(880, 880), "Game Board!");
    //sf::Style::Resize
    Board board(window);

   
    
    //sf::RectangleShape squareBoard(sf::Vector2f(80.f, 80.f));

    ///*sf::CircleShape shape(100.f);

    //shape.setFillColor(sf::Color::Green);*/

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
      //  window.draw(text);
        window.display();
    }

    return 0;
}

//#else 
/*
int main(void) {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Text Example");

    // Create a text object
    sf::Text text;
    sf::Font font;
    text.setFont(font);
    text.setString("Hello, SFML!");
    text.setCharacterSize(240);
    text.setFillColor(sf::Color::White);

    // Set the text position
    text.setPosition(100, 100);

    // Main loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the text
        window.draw(text);

        // Display the window
        window.display();
    }

    return 0;
}

#endif

*/
