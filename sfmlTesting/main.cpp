#include "game.h"

int main()
{
	srand((unsigned int)time(NULL));

	sf::RenderWindow window(sf::VideoMode(880 * 2, 880), "Game Board!");
	//sf::Style::Resize
	Board player1(window);
	Board player2(window);


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
		player1.drawBoard(0, 0);
		player2.drawBoard(11, 0);



		player2.placeShip("Cruiser", 'A', 6, 0);
		player2.placeBomb('A', 1);
		player1.placeShip("Destroyer", 'B', 5, 0);
		player2.placeBomb('B', 6);
		//  board.placeShip("Cruiser", 'E', 0, 90);
		//  window.draw(text);
		window.display();



	}


	game g1;
	g1.runGame();

	return 0;


}