#include "boardGame.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(880 * 2, 1200), "Game Board!");

	game g1(window);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {


			if (event.type == sf::Event::Closed)
				window.close();

		}


		window.clear();

		g1.runGame();
		// draw here

		window.display();


	}

	srand((unsigned int)time(NULL));





	return 0;


}