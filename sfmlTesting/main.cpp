#include "boardGame.h"

int main()
{

	//sf::RenderWindow window(sf::VideoMode(880 * 2, 1200), "Game Board!");

	game g1;

	while (gameWindow.isOpen()) {

		sf::Event event;

		while (gameWindow.pollEvent(event)) {


			if (event.type == sf::Event::Closed)
				gameWindow.close();

		}


		gameWindow.clear();

		g1.runGame();
		// draw here

		gameWindow.display();


	}

	srand((unsigned int)time(NULL));





	return 0;


}