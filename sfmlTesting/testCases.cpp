#include "boardGame.h"

// to test ato see if code is working it will be called in main then commented out

void testShipPlacement(void) //manually placing ships
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

		boardPlayer1.placeShip("Carrier", 'A', 1, 0); //placing carrier at a1 0 degrees
		boardPlayer1.placeShip("Battleship", 'B', 2, 90); //placing battleship at b2 90 degrees
		boardPlayer1.placeShip("Cruiser", 'C', 3, 180); // placing cruiser at c3 180 degrees
		boardPlayer1.placeShip("Submarine", 'D', 4, 270); //placing submarine at d4 270 degrees
		boardPlayer1.placeShip("Destroyer", 'E', 5, 360); //placing destroyer at e5 360 degrees
		gameWindow.display();

	}
}

void testBombPlacents(void) // manually placing bombs
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

		boardViewPlayer1.placeBomb('A', 1); // place bomb at a1
		boardViewPlayer1.placeBomb('B', 2); // place bomb at b2
		boardViewPlayer1.placeBomb('C', 3); // place bomb at c3
		boardViewPlayer1.placeBomb('D', 4); // place bomb at d4 
		boardViewPlayer1.placeBomb('E', 5); // place bomb at e5
		boardViewPlayer1.placeBomb('F', 6); // place bomb at f6
		boardViewPlayer1.placeBomb('G', 7); // place bomb at g7
		boardViewPlayer1.placeBomb('H', 8); // place bomb at h8
		gameWindow.display();

	}

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

	sf::RenderWindow testWindow(sf::VideoMode(800, 600), "SFML Window");

	while (testWindow.isOpen())
	{
		sf::Event event;
		while (testWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				testWindow.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePosition = sf::Mouse::getPosition(testWindow);
					if (mousePosition.x >= 400 && mousePosition.y >= 300)
					{
						std::cout << "User mouse input is working" << std::endl;
					}
				}
			}
		}

		testWindow.display();
	}



}

void testUserTextInput(void) // a popup that gets userinput for coodinates
{
	sf::RenderWindow window(sf::VideoMode(1000, 200), "Input Prompt");

	sf::Font font;
	if (!font.loadFromFile("Fonts/ARIAL.ttf")) {
		std::cout << "Error loading font" << std::endl;
		//break;
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

