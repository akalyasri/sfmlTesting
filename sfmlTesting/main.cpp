#include "boardGame.h"

int main()
{
    srand((unsigned int)time(NULL));


    sf::Music music;

    if (!music.openFromFile("Music/background.ogg")) {

        cout << "Error opening music file" << endl;


    }

    music.setVolume(20);
    music.play();


    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Battleship Menu");

    // load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Textures/sea.jpg")) {
        std::cout << "Error loading background texture." << std::endl;
        return 1;
    }
    sf::Sprite background(backgroundTexture);

    // load the font
    sf::Font font;
    if (!font.loadFromFile("Fonts/arialbd.ttf")) {
        std::cout << "Error loading font." << std::endl;
        return 1;
    }

    // create the title text
    sf::Text title("BATTLESHIP !!", font, 50);
    title.setPosition(200, 49);

    // create the "Play Game" text
    sf::Text playGame("Play Game", font, 30);
    playGame.setPosition(300, 200);

    // create the "Rules" text
    sf::Text rules("Rules", font, 30);
    rules.setPosition(340, 250);

    // create the "Exit" text
    sf::Text exit("Exit", font, 30);
    exit.setPosition(350, 300);

    // run the main loop
    while (window.isOpen()) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (playGame.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // play game option selected
                        window.close();
                        // game screen

                       
                        game g1;
                        g1.runGame();


                    }
                    else if (rules.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // rules option selected

                       /* window.clear();

                        sf::Text text("RULES:", font, 50);

                        window.draw(text);*/


                        window.close();

                        // rules screen
                        sf::RenderWindow rulesWindow(sf::VideoMode(800, 600), "Battleship Rules");
                        sf::Text rules;
                        rules.setFont(font);
                        rules.setString("Battleship Rules:\n\n1. Each player places their ships on the board.\n2. Players take turns guessing the locations of each other's ships.\n3. The first player to sink all of their opponent's ships wins!");
                        rules.setCharacterSize(24);
                        rules.setFillColor(sf::Color::White);
                        rules.setPosition(50, 50);

                        // Create a "Play Game" button
                        sf::RectangleShape playButton(sf::Vector2f(200, 50));
                        playButton.setFillColor(sf::Color::Transparent);
                        playButton.setOutlineThickness(2);
                        playButton.setOutlineColor(sf::Color::Black);
                        playButton.setPosition(300, 450);

                        sf::Text playText;
                        playText.setFont(font);
                        playText.setString("Play Game");
                        playText.setCharacterSize(24);
                        playText.setFillColor(sf::Color::White);
                        playText.setPosition(320, 460);


                        // Main loop
                        while (rulesWindow.isOpen())
                        {
                            // Handle events
                            sf::Event event;
                            while (rulesWindow.pollEvent(event))
                            {
                                if (event.type == sf::Event::Closed)
                                {
                                    rulesWindow.close();
                                }
                                else if (event.type == sf::Event::MouseButtonPressed)
                                {
                                    // Check if the "Play Game" button was clicked
                                    if (playButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                                    {
                                        rulesWindow.close();
                                        // Start the game here
                                       
                                        game g1;
                                        g1.runGame();

                                    }
                                }
                            }

                            // Clear the window
                            rulesWindow.clear(sf::Color::White);

                            rulesWindow.draw(background);

                            // Draw the rules text
                            rulesWindow.draw(rules);

                            // Draw the "Play Game" button
                            rulesWindow.draw(playButton);
                            rulesWindow.draw(playText);

                            // Display the window
                            rulesWindow.display();
                        }

                        window.close();
                        // game screen

                       
                    }
                    else if (exit.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // exit option selected
                        window.close();
                    }
                }
            }
        }

        // draw the background, title, and options
        window.clear();
        window.draw(background);
        window.draw(title);
        window.draw(playGame);
        window.draw(rules);
        window.draw(exit);
        window.display();
    }

   

	return 0;


}