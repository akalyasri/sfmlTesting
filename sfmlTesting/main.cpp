#include "boardGame.h"

int main()
{





	/*


	//sf::RenderWindow window(sf::VideoMode(880 * 2, 1200), "Game Board!");
	//while (gameWindow.isOpen()) {

	//	sf::Event event;

	//	while (gameWindow.pollEvent(event)) {


	//		if (event.type == sf::Event::Closed)
	//			gameWindow.close();

	//	}


	//	gameWindow.clear();

	//
	//	// draw here

	//	gameWindow.display();


	//}

	*/


    sf::Music music;

    if (!music.openFromFile("Music/background.ogg")) {

        cout << "Error opening music file" << endl;

    }

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
	if (!font.loadFromFile("Fonts/ARIAL.TTF")) {
		std::cout << "Error loading font." << std::endl;
		return 1;
	}

    // create the title text
    sf::Text title("BATTLESHIP!", font, 50);
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
						// TODO: launch game screen

						srand((unsigned int)time(NULL));
						game g1;
						g1.runGame();


                    }
                    else if (rules.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // rules option selected

                        window.clear();

                        sf::Text text("RULES:", font, 50);

                        window.draw(text);


                       // window.close();
                        // TODO: launch rules screen
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