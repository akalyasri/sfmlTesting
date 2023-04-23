#include "GameBoard.hpp"



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

void Board::placeShip(string shipName, char x, int y, int orientation) {

    // Convert Corrdinate

    float xCoord = float(80 * ((x+2) - 'A'));
    float yCoord = float((y+1) * 80);

    sf::Texture texture;

    if (shipName == "Carrier") {

        if (!texture.loadFromFile("ShipTypes/carrier_1x4.png")) {
            cout << "Error loading ship file" << endl;
        }

    }
    else if (shipName == "Battleship") {

    }
    else if (shipName == "Cruiser") {

        if (!texture.loadFromFile("ShipTypes/cruiser_1x3.png")) {
            cout << "Error loading ship file" << endl;
        }

    }
    else if (shipName == "Destroyer") {

    }
    else if (shipName == "Submarine") {

    }

 

  
    sf::Sprite sprite(texture);

    sprite.setPosition(xCoord, yCoord);
    //sprite.scale(.9f, .9f);
    sprite.setRotation(orientation);

    m_window.draw(sprite);
    m_window.display();

    sf::sleep(sf::milliseconds(1000)); // Add a delay of 100 milliseconds

    
    

}


