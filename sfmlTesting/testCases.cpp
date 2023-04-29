#include "boardGame.h"

// to test ato see if code is working it will be called in main then commented out

void testShipPlacement(void)
{

	Board boardPlayer1(gameWindow);
	Board boardViewPlayer1(gameWindow);

	gameWindow.clear();
	boardPlayer1.drawBoard(0, 0);
	boardViewPlayer1.drawBoard(11, 0);

	sf::Font font;
	if (!font.loadFromFile("Fonts/ARIAL.ttf"))
	{
		std::cerr << "Error loading font" << std::endl;
	}

	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();

		}

		boardPlayer1.placeShip("Carrier", 'A', 1, 0);
		boardPlayer1.placeShip("Battleship", 'B', 2, 90);
		boardPlayer1.placeShip("Cruiser", 'C', 3, 180);
		boardPlayer1.placeShip("Submarine", 'D', 4, 270);
		boardPlayer1.placeShip("Destroyer", 'E', 5, 360);
		gameWindow.display();

	}
}

void testBombPlacents(void)
{

	Board boardPlayer1(gameWindow);
	Board boardViewPlayer1(gameWindow);

	gameWindow.clear();
	boardPlayer1.drawBoard(0, 0);
	boardViewPlayer1.drawBoard(11, 0);

	sf::Font font;
	if (!font.loadFromFile("Fonts/ARIAL.ttf"))
	{
		std::cerr << "Error loading font" << std::endl;
	}

	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();

		}

		boardViewPlayer1.placeBomb('A', 1);
		boardViewPlayer1.placeBomb('B', 2);
		boardViewPlayer1.placeBomb('C', 3);
		boardViewPlayer1.placeBomb('D', 4);
		boardViewPlayer1.placeBomb('E', 5);
		boardViewPlayer1.placeBomb('F', 6);
		boardViewPlayer1.placeBomb('G', 7);
		boardViewPlayer1.placeBomb('H', 8);
		gameWindow.display();

	}

}


void testSFMLwindow(void) {



}

void testMouseInput(void) {



}

void testUserTextInput(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 200), "Input Prompt");

	sf::Font font;
	if (!font.loadFromFile("Fonts/ARIAL.ttf")) {
		std::cout << "Error loading font" << std::endl;
		break;
	}

	sf::Text prompt;
	prompt.setFont(font);
	prompt.setCharacterSize(24);
	prompt.setFillColor(sf::Color::White);
	prompt.setString("You picked a coordinate that has already been taken by other ship. Select a different coordinate (x y):");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(0, 40);

	std::string inputString;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode == '\r') {
					// Return input string when user presses enter
					std::cout << "User entered: " << inputString << std::endl;
					//return inputString;
					window.close();
				}
				else if (event.text.unicode == '\b') {
					// Handle backspace
					if (!inputString.empty()) {
						inputString.pop_back();
						text.setString(inputString);
					}
				}
				else {
					// Handle other input characters
					inputString += static_cast<char>(event.text.unicode);
					text.setString(inputString);
				}
			}
		}

		window.clear(sf::Color::Black);
		window.draw(prompt);
		window.draw(text);
		window.display();
	}

}

