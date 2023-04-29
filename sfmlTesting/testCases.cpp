#include "boardGame.h"

// to test ato see if code is working it will be called in main then commented out

void testShipPlacement(void) {





}

void testBombPlacents(void) {



}


void testSFMLwindow(void) {


	sf::RenderWindow testWindow(sf::VideoMode(800, 800), "SFML Window");

    sf::Font font;

    if (!font.loadFromFile("Fonts/arialbd.ttf")) {

        std::cout << "Error loading font." << std::endl;
        return;
    }

    sf::Text text("SFML window is working !!", font, 50);
    text.setPosition(200, 49);

    while (testWindow.isOpen()) {

        sf::Event event;
        while (testWindow.pollEvent(event)) {
           

            if (event.type == sf::Event::Closed) {

                testWindow.close();
            }
        }

        
        testWindow.draw(text);
        testWindow.display();
    }

}

void testMouseInput(void) {



}

void testUserTextInput(void) {


}

