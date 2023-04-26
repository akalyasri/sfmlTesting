#include "header.h"

class ship
{
public:
	ship()
	{
		player = NULL;
		hp = 0;
		identification = NULL;
		hit = 0;
		sunk = 0;
	}

	ship(int uPlayer, int uHP, char uIdentification, int uHit, int uSunk)
	{
		player = uPlayer;
		hp = uHP;
		identification = uIdentification;
		hit = uHit;
		sunk = uSunk;
	}
	virtual void setShip(int uHP, char uIdentification, int uHit, int uSunk)
	{

	}
	~ship()
	{

	}
	void setPlayer(int uPlayer)
	{
		player = uPlayer;
	}
	void setHP(int uHP)
	{
		hp = uHP;
	}
	void setIdentification(char uIdetification)
	{
		identification = uIdetification;
	}
	void setHit(int uHit)
	{
		hit = uHit;
	}
	void setSunk(int uSunk)
	{
		sunk = uSunk;
	}

	int getPlayer()
	{
		return player;
	}
	int getHP()
	{
		return hp;
	}
	char getIdentification()
	{
		return identification;
	}
	int getHit()
	{
		return hit;
	}
	int getSunk()
	{
		return sunk;
	}



	void setX(int uX)
	{
		x = uX;
	}
	void setY(int uY)
	{
		y = uY;
	}
	void setOrientation(int uRotation)
	{
		orintation = uRotation;
	}

	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getOrientation()
	{
		return orintation;
	}

private:
	int player;
	int hp;
	char identification;
	int hit;
	int sunk;

	int x = 0;
	int y = 0;
	int orintation = 0;
};


class destroyerShip : public ship
{
	destroyerShip(int uPlayer, int uHP, char uIdentification, int uHit, int uSunk) :ship(uPlayer, uHP, uIdentification, uHit, uSunk)
	{

	}


};


class con2Sfml // makes a layer that interacts with the console and sfml
{
public:
	con2Sfml()
	{

	}

	virtual int yesNo()
	{

		int choice = NO;


		printf("Would you like to place Manually or Automatic (0 for man || 1 for auto) \n");
		scanf("%d", &choice);

		while (choice != NO && choice != YES)
		{
			printf("Please type correctly ");
			scanf("%d", &choice);

		}

		return choice;
	}


	virtual string inputCheck(int type, vector<string> strings)
	{
		return "-1";
	}
};

class layer : public con2Sfml //public con2Sfml
{
public:
	layer()
	{

	}


	int yesNo() override
	{
		sf::RenderWindow window(sf::VideoMode(1000, 480), "SFML Keyboard Input");

		sf::Font font;
		if (!font.loadFromFile("Fonts/ARIAL.ttf"))
		{
			std::cerr << "Error loading font" << std::endl;
			return 1;
		}

		sf::Text promptText;
		promptText.setFont(font);
		promptText.setCharacterSize(24);
		promptText.setFillColor(sf::Color::White);
		promptText.setPosition(20, 20);
		promptText.setString("Would you like to place Manually or Automatic (0 for man || 1 for auto)");

		sf::Text inputText;
		inputText.setFont(font);
		inputText.setCharacterSize(24);
		inputText.setFillColor(sf::Color::White);
		inputText.setPosition(20, 70);

		std::string input;
		int number = -1;

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				else if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode == '\r' || event.text.unicode == '\n') // Enter key
					{
						if (input == "0" || input == "1")
						{
							number = std::stoi(input);
							std::cout << "You entered: " << number << std::endl;
							input.clear();
							promptText.setString("You entered: " + std::to_string(number));
						}
						else
						{
							std::cout << "Invalid input. Please try again." << std::endl;
							input.clear();
							promptText.setString("Invalid input. Please try again.");
						}
					}
					else if (event.text.unicode < 128) // ASCII character
					{
						char c = static_cast<char>(event.text.unicode);
						std::cout << c;
						input += c;
						inputText.setString(input);
					}
				}
			}

			window.clear();
			window.draw(promptText);
			window.draw(inputText);
			window.display();

			if (number == 0 || number == 1)
			{
				return number;
			}
		}

		return 0;

	}


	string inputCheck(int type, vector<string> strings) override
	{
		if (type == 1)
		{

			sf::RenderWindow window(sf::VideoMode(1000, 200), "Input Prompt");

			sf::Font font;
			if (!font.loadFromFile("Fonts/ARIAL.ttf")) {
				std::cout << "Error loading font" << std::endl;
				return NULL;
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
							return inputString;
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

			return 0;
		}

		if (type == 2)
		{
			sf::RenderWindow window(sf::VideoMode(1000, 200), "Input Prompt");

			sf::Font font;
			if (!font.loadFromFile("Fonts/ARIAL.ttf")) {
				std::cout << "Error loading font" << std::endl;
				return NULL;
			}

			sf::Text prompt;
			prompt.setFont(font);
			prompt.setCharacterSize(24);
			prompt.setFillColor(sf::Color::White);
			prompt.setString("Your X or Y is out of bounds, enter within the bound (0 <= X or Y <= 9): ");

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
							return inputString;
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

			return 0;
		}

		if (type == 3)
		{
			// Create a window
			sf::RenderWindow window(sf::VideoMode(1000, 200), "SFML Array and Input");

			// Define the font to be used
			sf::Font font;
			if (!font.loadFromFile("Fonts/ARIAL.ttf")) {
				cout << "Error: font could not be loaded" << endl;
				return "-1";
			}

			// Define the array of strings
			//string arr[] = { "You can Rotate Left", "You can Rotate Right", "You can Rotate Down", "You can Rotate Up" };

			// Create a text object to display the strings in the array
			sf::Text text("", font, 20);
			text.setPosition(50, 50);

			// Display each string in the array on a separate line in the window
			for (int i = 0; i < 4; i++) {
				if (!strings[i].empty()) {
					text.setString(strings[i]);
					window.draw(text);
					text.move(0, 30);
				}
			}

			// Ask the user to input a number
			int num;
			cout << "Enter a number: ";
			cin >> num;

			// Create a text object to display the input number
			sf::Text input(std::to_string(num), font, 20);
			input.setPosition(50, 200);
			window.draw(input);

			// Ask the user to input an index that contains characters
			int index;
			do {
				cout << "Enter an index that contains characters (0-4): ";
				cin >> index;
			} while (strings[index].empty());

			// Create a text object to display the input index and corresponding string in the array
			sf::Text output("Index " + std::to_string(index) + ": " + strings[index], font, 20);
			output.setPosition(50, 250);
			window.draw(output);

			// Display the window
			window.display();

			// Wait for the window to be closed
			while (window.isOpen()) {
				sf::Event event;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						window.close();
					}
				}
			}

			return 0;
		}

		if (type == 4)
		{
			const int WIDTH = 1000;
			const int HEIGHT = 200;
			const int NUM_STRINGS = 4;
			//const std::string strings[NUM_STRINGS] = { "You can Rotate Left", "You can Rotate Right", "You can Rotate Down", "You can Rotate Up" };

			sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Rotate Check");

			sf::Font font;
			if (!font.loadFromFile("Fonts/ARIAL.ttf")) {
				std::cout << "Error loading font file" << std::endl;
				return "-1";
			}

			sf::Text text;
			text.setFont(font);
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::White);
			text.setPosition(50, 50);

			int selectedNum = -1; // initialize to an invalid value

			while (window.isOpen() && selectedNum == -1) {
				sf::Event event;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						window.close();
				}

				window.clear(sf::Color::Black);

				// display strings
				for (int i = 0; i < NUM_STRINGS; i++) {
					if (strings[i] != "\0") {
						sf::Text text(strings[i], sf::Font(), 20);
						text.setPosition(50, i * 50 + 50);
						window.draw(text);
						window.display();
					}
				}

				// ask for user input
				sf::Text prompt("Enter a number: ", sf::Font(), 20);
				prompt.setPosition(50, 350);
				window.draw(prompt);
				window.display();

				std::string input;
				std::getline(std::cin, input);
				int num = std::stoi(input);

				// check if input is valid
				while (num < 0 || num >= NUM_STRINGS || strings[num] == "\0") {
					sf::Text error("Invalid input. Please enter a number corresponding to a non-empty string: ", sf::Font(), 20);
					error.setPosition(50, 400);
					window.draw(error);
					window.display();
					std::getline(std::cin, input);
					num = std::stoi(input);
				}

				// display selected string and store selected number
				sf::Text selectedString(strings[num], sf::Font(), 20);
				selectedString.setPosition(50, 450);
				window.draw(selectedString);
				window.display();
				selectedNum = num;
			}

			return std::to_string(selectedNum);
		}
	}

};





class fleet
{
public:
	fleet()
	{
		carrier = new ship(PLAYER1, 5, 'p', 0, NSUNK);
		battleship = new ship(PLAYER1, 4, 'b', 0, NSUNK);
		cruiser = new ship(PLAYER1, 3, 'c', 0, NSUNK);
		submarine = new ship(PLAYER1, 3, 's', 0, NSUNK);
		destroyer = new ship(PLAYER1, 2, 'd', 0, NSUNK);

	}

	ship* carrier;
	ship* battleship;
	ship* cruiser;
	ship* submarine;
	ship* destroyer;

};

class logBook //keeps track of shots fired
{

public:
	vector<int> x;
	vector<int> y;
};

class board
{
public:
	board()
	{
		int rowIndex = 0, colIndex = 0;

		for (; rowIndex < numRows; ++rowIndex)
		{
			for (colIndex = 0; colIndex < numCols; ++colIndex)
			{
				boardPlayer1[rowIndex][colIndex] = '~';
				boardPlayer2[rowIndex][colIndex] = '~';
				boardViewPlayer1[rowIndex][colIndex] = '~';
				boardViewPlayer2[rowIndex][colIndex] = '~';
			}
		}
	}

	void printBoard(int type)
	{
		int rowIndex = 0, colIndex = 0;

		printf("%4d%3d%3d%3d%3d%3d%3d%3d%3d%3d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9); //prints the column grid numbers
		for (; rowIndex < numRows; ++rowIndex)
		{
			printf("%d", rowIndex); // prints the horizonal grid numbers
			for (colIndex = 0; colIndex < numCols; ++colIndex)
			{
				if (type == BOARDPLAYER1)
				{
					printf("%3c", boardPlayer1[rowIndex][colIndex]); // printing the ocean
				}
				else if (type == BOARDVIEWPLAYER1)
				{
					printf("%3c", boardViewPlayer1[rowIndex][colIndex]);
				}
				else if (type == BOARDPLAYER2)
				{
					printf("%3c", boardPlayer2[rowIndex][colIndex]); // printing the ocean
				}
				else if (type == BOARDVIEWPLAYER2)
				{
					printf("%3c", boardViewPlayer2[rowIndex][colIndex]);
				}
				else
				{
					cout << "Wrong player input" << endl;
				}

			}

			putchar('\n');
		}
	}

	void fire(int whoPlay)
		// if player is the one who is firing, the board[][], and the structs must be set to computer and vice versa
	{
		int x = 0, y = 0;
		char shipHit = '\0';
		int tryAgain = YES;
		int win = NO;

		if (whoPlay == PLAYER1) // PLAYER 1 game
		{
			printf("Type in the coordeinate to fire (X Y) ");
			scanf("%d %d", &x, &y);

			while (tryAgain == YES)
			{
				while (tryAgain == YES)
				{
					if (x > 9 && x < 0 && y > 9 && y < 0)
					{
						printf("\nYour X or Y is out of bounds, enter within the bound (0 <= x <= 9) (0 <= y <= 9): ");
						scanf("%d %d", &x, &y);
					}
					else
					{
						tryAgain = NO;
					}
				}

			}
			tryAgain = YES;
			while (tryAgain == YES)
			{
				while (tryAgain == YES)
				{
					if (boardViewPlayer1[y][x] == 'o' || boardViewPlayer1[y][x] == 'x')
					{
						printf("\n Your coordinate has already been hit or shot at try again (x y): ");
						scanf("%d %d", &x, &y);
					}
					else
					{
						tryAgain = NO;
					}
				}

			}

			if (boardPlayer2[y][x] == '~')
			{
				//fprintf(infile, "Player has missed || Coordinate: (%d,%d)\n", x, y);
				printf("You missed!\n");
				boardViewPlayer1[y][x] = 'o';
				boardPlayer2[y][x] = 'o';


				logPlayer1.x.push_back(x); //keeps track of shots
				logPlayer1.y.push_back(y);


			}
			else
			{
				if (fleetPlayer2.carrier->getIdentification() == boardPlayer2[y][x])
				{
					printf("You hit carrier\n");
					//fprintf(infile, "Player has scored a hit on the carrier || Coordinate: (%d,%d)\n ", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.carrier->setHP(fleetPlayer2.carrier->getHP() - 1);
					if (fleetPlayer2.carrier->getHP() == 0)
					{
						printf("You sunk carrier\n");
						//fprintf(infile, "Player has sunk the carrier || Coordinate: (%d,%d)\n", x, y);
						//playerCarrier->sunk = YES;
						fleetPlayer2.carrier->setSunk(YES);
					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else if (fleetPlayer2.battleship->getIdentification() == boardPlayer2[y][x])
				{
					printf("You hit battleship\n");
					//fprintf(infile, "Player has scored a hit on the battleship || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.battleship->setHP(fleetPlayer2.battleship->getHP() - 1);
					if (fleetPlayer2.battleship->getHP() == 0)
					{
						printf("You sunk battleship\n");
						//fprintf(infile, "Player has sunk the battleship || Coordinate: (%d,%d)\n", x, y);
						//playerBattleship->sunk = YES;
						fleetPlayer2.battleship->setSunk(YES);

					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else if (fleetPlayer2.cruiser->getIdentification() == boardPlayer2[y][x])
				{
					printf("You hit cruiser\n");
					//fprintf(infile, "Player has scored a hit on the cruiser || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.cruiser->setHP(fleetPlayer2.cruiser->getHP() - 1);
					if (fleetPlayer2.cruiser->getHP() == 0)
					{
						printf("You sunk cruiser\n");
						//fprintf(infile, "Player has sunkt the cruiser || Coordinate: (%d,%d)\n", x, y);
						//playerCruiser->sunk = YES;
						fleetPlayer2.cruiser->setSunk(YES);

					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else if (fleetPlayer2.submarine->getIdentification() == boardPlayer2[y][x])
				{
					printf("You hit submarine\n");
					//fprintf(infile, "Player has scored a hit on the submarine || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.submarine->setHP(fleetPlayer2.submarine->getHP() - 1);
					if (fleetPlayer2.submarine->getHP() == 0)
					{
						printf("You sunk submarine\n");
						//fprintf(infile, "Player has sunk the submarine || Coordinate: (%d,%d)\n", x, y);
						//playerSubmarine->sunk = YES;
						fleetPlayer2.submarine->setSunk(YES);

					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else if (fleetPlayer1.destroyer->getIdentification() == boardPlayer2[y][x])
				{
					printf("You hit destroyer\n");
					//fprintf(infile, "Player has scored a hit on the destroyer || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.destroyer->setHP(fleetPlayer2.destroyer->getHP() - 1);
					if (fleetPlayer2.destroyer->getHP() == 0)
					{
						printf("You sunk destroyer\n");
						//fprintf(infile, "Player has sunk the destroyer || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer2.destroyer->setSunk(YES);

					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else
				{
					//printf("\nSomething is wrong with your code"); // debug code
				}

				if (fleetPlayer2.carrier->getSunk() == YES && fleetPlayer2.carrier->getSunk() == YES && fleetPlayer2.carrier->getSunk() == YES && fleetPlayer2.carrier->getSunk() == YES && fleetPlayer2.carrier->getSunk() == YES)
				{
					cout << "Player Has Won!" << endl;
					status[0] = YES;
					//fprintf(infile, "Player has won! \n");

				}
			}


		}
		else
		{
			x = rand() % 9 + 0;
			y = rand() % 9 + 0;

			while (tryAgain == YES)
			{
				while (tryAgain == YES)
				{
					if (x > 9 && x < 0 && y > 9 && y < 0 && boardViewPlayer2[y][x] == 'o' && boardViewPlayer2[y][x] == 'x')
					{
						x = rand() % 9 + 0;
						y = rand() % 9 + 0;
					}
					else
					{
						tryAgain = NO;
					}
				}

			}
			tryAgain = YES;
			while (tryAgain == YES)
			{
				while (tryAgain == YES)
				{
					if (boardViewPlayer2[y][x] == 'o' || boardViewPlayer2[y][x] == 'x')
					{
						//printf("\n Your coordinate has already been hit or shot at try again (x y): ");
						x = rand() % 9 + 0;
						y = rand() % 9 + 0;
					}
					else
					{
						tryAgain = NO;
					}
				}

			}

			if (boardPlayer1[y][x] == '~')
			{
				//fprintf(infile, "Player has missed || Coordinate: (%d,%d)\n", x, y);
				printf("CPU missed!\n");
				boardPlayer1[y][x] = 'o';
				boardViewPlayer2[y][x] = 'o';

				logPlayer2.x.push_back(x); //keeps track of shots
				logPlayer2.y.push_back(y);


			}
			else
			{
				if (fleetPlayer1.carrier->getIdentification() == boardPlayer1[y][x])
				{
					printf("Computer hit carrier \n");
					//fprintf(infile, "Computer has scored a hit on the carrier || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerCarrier->hit--;
					fleetPlayer1.carrier->setHP(fleetPlayer1.carrier->getHP() - 1);
					if (fleetPlayer1.carrier->getHP() == 0)
					{
						printf("Computer sunk carrier\n");
						//fprintf(infile, "Computer has sunk the carrier || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.carrier->setSunk(YES);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);
				}
				else if (fleetPlayer1.battleship->getIdentification() == boardPlayer1[y][x])
				{
					printf("Computer hit battleship \n");
					//fprintf(infile, "Computer has scored a hit on the battleship || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerBattleship->hit--;
					fleetPlayer1.battleship->setHP(fleetPlayer1.battleship->getHP() - 1);
					if (fleetPlayer1.battleship->getHP() == 0)
					{
						printf("Computer sunk battleship\n");
						//fprintf(infile, "Computer has sunk the battleship || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.battleship->setSunk(YES);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);

				}
				else if (fleetPlayer1.cruiser->getIdentification() == boardPlayer1[y][x])
				{
					printf("Computer hit cruiser\n");
					//fprintf(infile, "Computer has scored a hit on the cruiser || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerCruiser->hit--;
					fleetPlayer1.cruiser->setHP(fleetPlayer1.cruiser->getHP() - 1);
					if (fleetPlayer1.cruiser->getHP() == 0)
					{
						printf("Computer sunk cruiser\n");
						//fprintf(infile, "Computer has sunk the cruiser || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.cruiser->setSunk(YES);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);
				}
				else if (fleetPlayer1.submarine->getIdentification() == boardPlayer1[y][x])
				{
					printf("Computer hit submarine\n");
					//fprintf(infile, "Computer has scored a hit on the submarine || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerSubmarine->hit--;
					fleetPlayer1.submarine->setHP(fleetPlayer1.submarine->getHP() - 1);
					if (fleetPlayer1.submarine->getHP() == 0)
					{
						printf("Computer sunk submarine\n");
						//fprintf(infile, "Computer has sunk the submarine || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.submarine->setSunk(YES);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);
				}
				else if (fleetPlayer1.destroyer->getIdentification() == boardPlayer1[y][x])
				{
					printf("Computer hit destroyer \n");
					//fprintf(infile, "Computer has scored a hit on the destroyer || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerDestroyer->hit--;
					fleetPlayer1.destroyer->setHP(fleetPlayer1.destroyer->getHP() - 1);
					if (fleetPlayer1.destroyer->getHP() == 0)
					{
						printf("Computer sunk destroyer\n");
						//fprintf(infile, "Computer has sunk the destroyer || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.destroyer->setSunk(YES);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);
				}
				else
				{
					printf("\n CPU Something is wrong with your code");
				}

				if (fleetPlayer2.carrier->getSunk() == YES && fleetPlayer2.battleship->getSunk() == YES && fleetPlayer2.cruiser->getSunk() == YES && fleetPlayer2.submarine->getSunk() == YES && fleetPlayer2.destroyer->getSunk() == YES)
				{
					cout << "Computer Has Won" << endl;
					status[1] = YES;
					//fprintf(infile, "Computer has won!\n");

				}

			}



		}

	}

	void placeShip(int whoPlay)
	{
		con2Sfml* sfmlLayer = new layer;

		if (whoPlay == PLAYER1)
		{
			if (sfmlLayer->yesNo() == 0)
			{
				printf("Pick the first coordinate to place your carrier (X Y): ");
				placeMan(boardPlayer1, 4, fleetPlayer1.carrier->getIdentification(), fleetPlayer1);
				system("cls");
				printBoard(PLAYER1);

				printf("Pick the first coordinate to place your battleship (X Y): ");
				placeMan(boardPlayer1, 3, fleetPlayer1.battleship->getIdentification(), fleetPlayer1);
				system("cls");
				printBoard(PLAYER1);

				printf("Pick the first coordinate to place your cruiser (X Y): ");
				placeMan(boardPlayer1, 2, fleetPlayer1.cruiser->getIdentification(), fleetPlayer1);
				system("cls");
				printBoard(PLAYER1);

				printf("Pick the first coordinate to place your submarine (X Y): ");
				placeMan(boardPlayer1, 2, fleetPlayer1.submarine->getIdentification(), fleetPlayer1);
				system("cls");
				printBoard(PLAYER1);

				printf("Pick the first coordinate to place your destroyer (X Y): ");
				placeMan(boardPlayer1, 1, fleetPlayer1.destroyer->getIdentification(), fleetPlayer1);
				system("cls");
				//print_board(board, 10, 10);

			}
			else
			{
				placeAuto(boardPlayer1, 4, fleetPlayer1.carrier->getIdentification(), fleetPlayer1);

				placeAuto(boardPlayer1, 3, fleetPlayer1.battleship->getIdentification(), fleetPlayer1);

				placeAuto(boardPlayer1, 2, fleetPlayer1.cruiser->getIdentification(), fleetPlayer1);

				placeAuto(boardPlayer1, 2, fleetPlayer1.submarine->getIdentification(), fleetPlayer1);

				placeAuto(boardPlayer1, 1, fleetPlayer1.destroyer->getIdentification(), fleetPlayer1);
				system("cls");
				//print_board(board, 10, 10);
			}
		}
		if (whoPlay == PLAYER2)
		{
			placeAuto(boardPlayer2, 4, fleetPlayer2.carrier->getIdentification(), fleetPlayer2);

			placeAuto(boardPlayer2, 3, fleetPlayer2.battleship->getIdentification(), fleetPlayer2);

			placeAuto(boardPlayer2, 2, fleetPlayer2.cruiser->getIdentification(), fleetPlayer2);

			placeAuto(boardPlayer2, 2, fleetPlayer2.submarine->getIdentification(), fleetPlayer2);

			placeAuto(boardPlayer2, 1, fleetPlayer2.destroyer->getIdentification(), fleetPlayer2);
		}

		delete sfmlLayer;
	}

	int getStatusPlayer1()
	{
		return status[0];
	}
	int getStatusPlayer2()
	{
		return status[1];
	}

	logBook* getLogPlayer1()
	{
		return &logPlayer1;
	}
	logBook* getLogPlayer2()
	{
		return &logPlayer2;
	}

	fleet* getFleetPlayer1()
	{
		return &fleetPlayer1;
	}
	fleet* getFleetPlayer2()
	{
		return &fleetPlayer2;
	}


private:
	char boardPlayer1[10][10] = { {'\0'}, {'\0'} };
	char boardPlayer2[10][10] = { {'\0'}, {'\0'} };

	char boardViewPlayer1[10][10] = { {'\0'},{'\0'} }; // the offensive board. Show where the player fire his shots and sees if he misses or scores a hit
	char boardViewPlayer2[10][10] = { {'\0'},{'\0'} };

	int numRows = 10;
	int numCols = 10;

	fleet fleetPlayer1;
	fleet fleetPlayer2;

	logBook logPlayer1;
	logBook logPlayer2;

	int status[2] = { 0,0 };

	int infoX;
	int infoY;
	int infoRotation;



protected:
	/*int yesNo(int type)
	{
		int choice = NO;

		if (type == 1)
		{
			printf("Would you like to place Manually or Automatic (0 for man || 1 for auto) \n");
			scanf("%d", &choice);

			while (choice != NO && choice != YES)
			{
				printf("Please type correctly ");
				scanf("%d", &choice);

			}


		}
		return choice;

	}*/

	void placeMan(char board[][10], int size, char identification, class fleet& ref)
	{
		int x = 0, y = 0;
		int placeable = YES;
		int rotation[4] = { 0 };
		// left, right, down, up

		int choice = 0;
		vector<string> rotateString;

		// scanf("%d %d", &x, &y); 
		inputCheck(1, board, &x, &y, rotation, &choice, rotateString); // x and y input



		for (int i = x; (i >= x - size); i--) // left check
		{
			if ((placeable == YES) && (board[y][i] == '~') && (x - size >= 0))
			{

			}
			else
			{
				placeable = NO;
			}

		}
		if (placeable == YES)
		{
			rotation[0] = 1;
		}
		placeable = YES;

		for (int i = x; (i <= x + size); i++) // right check
		{
			if ((placeable == YES) && (board[y][i] == '~') && (x + size <= 10))
			{

			}
			else
			{
				placeable = NO;
			}

		}
		if (placeable == YES)
		{
			rotation[1] = 1;
		}
		placeable = YES;

		for (int i = y; (i <= y + size); i++) // down check
		{
			if ((placeable == YES) && (board[i][x] == '~') && (y + size <= 9))
			{

			}
			else
			{
				placeable = NO;
			}

		}
		if (placeable == YES)
		{
			rotation[2] = 1;
		}
		placeable = YES;

		for (int i = y; (i >= y - size); i--) // up check
		{
			if ((placeable == YES) && (board[i][x] == '~') && (y + size >= 0))
			{

			}
			else
			{
				placeable = NO;
			}

		}
		if (placeable == YES)
		{
			rotation[3] = 1;
		}
		placeable = YES;



		if (rotation[0] == 1)
		{
			printf("1) You can rotate left\n");
			rotateString.push_back("1) You can rotate left");
		}
		else
		{
			rotateString.push_back("\0");
		}

		if (rotation[1] == 1)
		{
			printf("2) You can rotate right\n");
			rotateString.push_back("2) You can rotate right");
		}
		else
		{
			rotateString.push_back("\0");
		}

		if (rotation[2] == 1)
		{
			printf("3) You can rotate down\n");
			rotateString.push_back("3) You can rotate down");
		}
		else
		{
			rotateString.push_back("\0");
		}

		if (rotation[3] == 1)
		{
			printf("4) You can roate up\n");
			rotateString.push_back("4) You can roate up");
		}
		else
		{
			rotateString.push_back("\0");
		}

		// what if no roations were found? Put in check code

		printf("What would you like to do? Pick the corresponding number: ");
		//scanf("%d", &choice);
		inputCheck(2, board, &x, &y, rotation, &choice, rotateString); // rotation choice input

		int uRot = 0;

		switch (choice)
		{
		case 1: // rotate left
			uRot = 180;
			for (int i = x; i >= x - size; i--)
			{
				board[y][i] = identification;
			}
			break;

		case 2: // rotate rigght
			uRot = 0;
			for (int i = x; i <= x + size; i++)
			{
				board[y][i] = identification;
			}
			break;

		case 3: // rotate down
			uRot = 90;
			for (int i = y; i <= y + size; i++)
			{
				board[i][x] = identification;
			}
			break;

		case 4: // roate up
			uRot = 270;
			for (int i = y; i >= y - size; i--)
			{
				board[i][x] = identification;
			}
			break;


		}

		/////////////////////////////////////////////////////////////////////


		switch (identification)
		{
		case 'p':
			ref.carrier->setX(x);
			ref.carrier->setY(y);
			ref.carrier->setOrientation(uRot);
			break;
		case 'b':
			ref.battleship->setX(x);
			ref.battleship->setY(y);
			ref.battleship->setOrientation(uRot);
			break;
		case 'c':
			ref.cruiser->setX(x);
			ref.cruiser->setY(y);
			ref.cruiser->setOrientation(uRot);
			break;
		case 's':
			ref.submarine->setX(x);
			ref.submarine->setY(y);
			ref.submarine->setOrientation(uRot);
			break;
		case 'd':
			ref.destroyer->setX(x);
			ref.destroyer->setY(y);
			ref.destroyer->setOrientation(uRot);
			break;
		}



		/////////////////////////////////////////////////////////////////////

		rotation[0] = 0;
		rotation[1] = 0;
		rotation[2] = 0;
		rotation[3] = 0;



	}
	void inputCheck(int checkType, char board[][10], int* x, int* y, int rotation[], int* choice, vector<string> rotationString)
	{
		int tryAgain = YES;
		con2Sfml* sfmlLayer = new layer;

		if (checkType == 1)
		{
			scanf("%d %d", x, y);

			while (tryAgain == YES)
			{
				if (board[*y][*x] != '~')
				{
					/*printf("\nYou picked a coordinate that has already been taken by other ship\n Select a different coordinate: ");
					scanf("%d %d", x, y);*/
					sfmlLayer->inputCheck(1, rotationString);


				}
				else
				{

					while (tryAgain == YES)
					{
						if (*x > 9 || *x < 0)
						{
							/*printf("\nYour X is out of bounds, enter within the bound (0 <= x <= 9): ");
							scanf("%d", x);*/
							*x = stoi(sfmlLayer->inputCheck(2, rotationString));
						}
						else
						{
							tryAgain = NO;
						}
					}
					tryAgain = YES;

					while (tryAgain == YES)
					{
						if (*y > 9 || *y < 0)
						{
							/*printf("\nYour Y is out of bounds, enter within the bound (0 <= x <= 9): ");
							scanf("%d", y);*/
							*y = stoi(sfmlLayer->inputCheck(2, rotationString));
						}
						else
						{
							tryAgain = NO;
						}
					}
					tryAgain = NO;

				}

			}
		}


		if (checkType == 2)
		{
			scanf("%d", choice);
			//while (tryAgain == YES)
			//{

			//	if (rotation[*choice - 1] != 1)
			//	{
			//		/*printf("\n You selected an invalid number, selec a valid rotation: ");
			//		scanf("%d", choice);*/

			//		*choice = stoi(sfmlLayer->inputCheck(4, rotationString));

			//	}
			//	else
			//	{
			//		tryAgain = NO;
			//	}
			//}

			* choice = stoi(sfmlLayer->inputCheck(3, rotationString));

		}
	}
	void parseString(int* x, int* y)
	{

	}

	void placeAuto(char board[][10], int size, char identification, class fleet& ref)
	{
		int x = 0, y = 0;
		int placeable = YES;
		int rotation[4] = { 0 };
		// left, right, down, up

		int choice = 0;

		// scanf("%d %d", &x, &y); 
		autoCheck(1, board, &x, &y, rotation, &choice); // x and y input

		for (int i = x; (i >= x - size); i--) // left check
		{
			if ((placeable == YES) && (board[y][i] == '~') && (x - size >= 0))
			{

			}
			else
			{
				placeable = NO;
			}

		}
		if (placeable == YES)
		{
			rotation[0] = 1;
		}
		placeable = YES;

		for (int i = x; (i <= x + size); i++) // right check
		{
			if ((placeable == YES) && (board[y][i] == '~') && (x + size <= 9))
			{

			}
			else
			{
				placeable = NO;
			}

		}
		if (placeable == YES)
		{
			rotation[1] = 1;
		}
		placeable = YES;

		for (int i = y; (i <= y + size); i++) // down check
		{
			if ((placeable == YES) && (board[i][x] == '~') && (y + size <= 9))
			{

			}
			else
			{
				placeable = NO;
			}

		}
		if (placeable == YES)
		{
			rotation[2] = 1;
		}
		placeable = YES;

		for (int i = y; (i >= y - size); i--) // up check
		{
			if ((placeable == YES) && (board[i][x] == '~') && (y + size >= 0))
			{

			}
			else
			{
				placeable = NO;
			}

		}
		if (placeable == YES)
		{
			rotation[3] = 1;
		}
		placeable = YES;

		autoCheck(2, board, &x, &y, rotation, &choice); // rotation choice input
		int uRot;

		switch (choice)
		{
		case 1: // rotate left
			uRot = 180;
			for (int i = x; i >= x - size; i--)
			{
				board[y][i] = identification;
			}
			break;

		case 2: // rotate rigght
			uRot = 0;
			for (int i = x; i <= x + size; i++)
			{
				board[y][i] = identification;
			}
			break;

		case 3: // rotate down
			uRot = 90;
			for (int i = y; i <= y + size; i++)
			{
				board[i][x] = identification;
			}
			break;

		case 4: // roate up
			uRot = 270;
			for (int i = y; i >= y - size; i--)
			{
				board[i][x] = identification;
			}
			break;


		}

		/////////////////////////////////////////////////////////////////////


		switch (identification)
		{
		case 'p':
			ref.carrier->setX(x);
			ref.carrier->setY(y);
			ref.carrier->setOrientation(uRot);
			break;
		case 'b':
			ref.battleship->setX(x);
			ref.battleship->setY(y);
			ref.battleship->setOrientation(uRot);
			break;
		case 'c':
			ref.cruiser->setX(x);
			ref.cruiser->setY(y);
			ref.cruiser->setOrientation(uRot);
			break;
		case 's':
			ref.submarine->setX(x);
			ref.submarine->setY(y);
			ref.submarine->setOrientation(uRot);
			break;
		case 'd':
			ref.destroyer->setX(x);
			ref.destroyer->setY(y);
			ref.destroyer->setOrientation(uRot);
			break;
		}



		/////////////////////////////////////////////////////////////////////

		rotation[0] = 0;
		rotation[1] = 0;
		rotation[2] = 0;
		rotation[3] = 0;



	}
	void autoCheck(int checkType, char board[][10], int* x, int* y, int rotation[], int* choice)
	{
		int tryAgain = YES;

		if (checkType == 1)
		{
			*x = rand() % 9 + 0;
			*y = rand() % 9 + 0;

			while (tryAgain == YES)
			{
				if (board[*y][*x] != '~')
				{
					//printf("\nYou picked a coordinate that has already been taken by other ship\n Select a different coordinate: ");
					*x = rand() % 9 + 0;
					*y = rand() % 9 + 0;

				}
				else
				{

					while (tryAgain == YES)
					{
						if (*x > 9 && *x < 0)
						{
							//printf("\nYour X is out of bounds, enter within the bound (0 <= x <= 9): ");
							*x = rand() % 9 + 0;
						}
						else
						{
							tryAgain = NO;
						}
					}
					tryAgain = YES;

					while (tryAgain == YES)
					{
						if (*y > 9 && *y < 0)
						{
							//printf("\nYour Y is out of bounds, enter within the bound (0 <= x <= 9): ");
							*y = rand() % 9 + 0;
						}
						else
						{
							tryAgain = NO;
						}
					}
					tryAgain = NO;

				}

			}
		}


		if (checkType == 2)
		{
			*choice = rand() % 4 + 1;
			while (tryAgain == YES)
			{

				if (rotation[*choice - 1] != 1)
				{
					//printf("\n You selected an invalid number, selec a valid rotation: ");
					*choice = rand() % 4 + 1;
				}
				else
				{
					tryAgain = NO;
				}
			}

		}
	}
};



class game
{
public:
	game()
	{

	}


	void displayPlayer1(int type)
	{


		sf::RenderWindow window(sf::VideoMode(880 * 2, 1200), "Game Board!");
		sf::Font font;
		if (!font.loadFromFile("Fonts/ARIAL.ttf"))
		{
			std::cerr << "Error loading font" << std::endl;
		}
		Board boardPlayer1(window);
		Board boardViewPlayer1(window);

		while (window.isOpen())
		{
			if (type == 0)

			{


				window.clear();
				boardPlayer1.drawBoard(0, 0);
				boardViewPlayer1.drawBoard(11, 0);

				cout << "Carrier (" << fleetPlayer1->carrier->getX() << ", " << fleetPlayer1->carrier->getY() << ")" << "Rotation: " << fleetPlayer1->carrier->getOrientation() << endl;
				cout << "Battleship (" << fleetPlayer1->battleship->getX() << ", " << fleetPlayer1->battleship->getY() << ")" << "Rotation: " << fleetPlayer1->battleship->getOrientation() << endl;
				cout << "Cruiser (" << fleetPlayer1->cruiser->getX() << ", " << fleetPlayer1->cruiser->getY() << ")" << "Rotation: " << fleetPlayer1->cruiser->getOrientation() << endl;
				cout << "Submarine (" << fleetPlayer1->submarine->getX() << ", " << fleetPlayer1->submarine->getY() << ")" << "Rotation: " << fleetPlayer1->submarine->getOrientation() << endl;
				cout << "Destroyer (" << fleetPlayer1->destroyer->getX() << ", " << fleetPlayer1->destroyer->getY() << ")" << "Rotation: " << fleetPlayer1->destroyer->getOrientation() << endl;


				sf::Text text;
				text.setFont(font);
				text.setCharacterSize(24);
				text.setFillColor(sf::Color::White);
				text.setPosition(20, 1100);
				text.setString("Hello World");
				window.draw(text);
				window.display();
			}
			else if (type == 1)
			{
				window.clear();
				boardPlayer1.drawBoard(0, 0);
				boardViewPlayer1.drawBoard(11, 0);
				boardPlayer1.placeShip("Carrier", num2Char[fleetPlayer1->carrier->getX()], fleetPlayer1->carrier->getY(), fleetPlayer1->carrier->getOrientation());
				boardPlayer1.placeShip("Battleship", num2Char[fleetPlayer1->battleship->getX()], fleetPlayer1->battleship->getY(), fleetPlayer1->battleship->getOrientation());
				boardPlayer1.placeShip("Cruiser", num2Char[fleetPlayer1->cruiser->getX()], fleetPlayer1->cruiser->getY(), fleetPlayer1->cruiser->getOrientation());
				boardPlayer1.placeShip("Submarine", num2Char[fleetPlayer1->submarine->getX()], fleetPlayer1->submarine->getY(), fleetPlayer1->submarine->getOrientation());
				boardPlayer1.placeShip("Destroyer", num2Char[fleetPlayer1->destroyer->getX()], fleetPlayer1->destroyer->getY(), fleetPlayer1->destroyer->getOrientation());

				for (int i = 0; i < logPlayer1->x.size(); i++)
				{
					boardViewPlayer1.placeBomb(num2Char[logPlayer1->x[i]], logPlayer1->y[i]);
				}
				for (int i = 0; i < logPlayer2->x.size(); i++)
				{
					boardPlayer1.placeBomb(num2Char[logPlayer2->x[i]], logPlayer2->y[i]);
				}

				sf::Text text;
				text.setFont(font);
				text.setCharacterSize(24);
				text.setFillColor(sf::Color::White);
				text.setPosition(20, 1100);
				text.setString("Hello World");
				window.draw(text);
				window.display();
			}
		}
	}

	void runGame()
	{
		sf::RenderWindow window(sf::VideoMode(880 * 2, 1200), "Game Board!");
		//sf::Style::Resize
		Board boardPlayer1(window);
		Board boardViewPlayer1(window);


		sf::Font font;
		if (!font.loadFromFile("Fonts/ARIAL.ttf"))
		{
			std::cerr << "Error loading font" << std::endl;
		}


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

			}

			char dummyChar = '\0';
			//b1.printBoard(BOARDPLAYER1);
			b1.placeShip(PLAYER1);

			// Placing ships on computer's board
			b1.placeShip(PLAYER2);
			//printf("Computer Board\n"); // debug code, speeds up testing of game
			//b1.printBoard(BOARDPLAYER2);

			//////////////////////////////////////////////////////////////// IMPORTANT!! GIVES ACCESS TO SHIP COORDINATES AND SHOTS FIRED
			logPlayer1 = b1.getLogPlayer1(); //vector
			logPlayer2 = b1.getLogPlayer2();

			fleetPlayer1 = b1.getFleetPlayer1();
			fleetPlayer2 = b1.getFleetPlayer2();
			//////////////////////////////////////////////////////////////// To access ship info go to fleetPlayer->shipName->get____ ||to access shots fired history go to logPlayer1->x.__
			int adjust = 0;

			window.clear();
			boardPlayer1.drawBoard(0, 0);
			boardViewPlayer1.drawBoard(11, 0);

			cout << "Carrier (" << fleetPlayer1->carrier->getX() << ", " << fleetPlayer1->carrier->getY() << ")" << "Rotation: " << fleetPlayer1->carrier->getOrientation() << endl;
			cout << "Battleship (" << fleetPlayer1->battleship->getX() << ", " << fleetPlayer1->battleship->getY() << ")" << "Rotation: " << fleetPlayer1->battleship->getOrientation() << endl;
			cout << "Cruiser (" << fleetPlayer1->cruiser->getX() << ", " << fleetPlayer1->cruiser->getY() << ")" << "Rotation: " << fleetPlayer1->cruiser->getOrientation() << endl;
			cout << "Submarine (" << fleetPlayer1->submarine->getX() << ", " << fleetPlayer1->submarine->getY() << ")" << "Rotation: " << fleetPlayer1->submarine->getOrientation() << endl;
			cout << "Destroyer (" << fleetPlayer1->destroyer->getX() << ", " << fleetPlayer1->destroyer->getY() << ")" << "Rotation: " << fleetPlayer1->destroyer->getOrientation() << endl;



			boardPlayer1.placeShip("Carrier", num2Char[fleetPlayer1->carrier->getX()], fleetPlayer1->carrier->getY(), fleetPlayer1->carrier->getOrientation());
			boardPlayer1.placeShip("Battleship", num2Char[fleetPlayer1->battleship->getX()], fleetPlayer1->battleship->getY(), fleetPlayer1->battleship->getOrientation());
			boardPlayer1.placeShip("Cruiser", num2Char[fleetPlayer1->cruiser->getX()], fleetPlayer1->cruiser->getY(), fleetPlayer1->cruiser->getOrientation());
			boardPlayer1.placeShip("Submarine", num2Char[fleetPlayer1->submarine->getX()], fleetPlayer1->submarine->getY(), fleetPlayer1->submarine->getOrientation());
			boardPlayer1.placeShip("Destroyer", num2Char[fleetPlayer1->destroyer->getX()], fleetPlayer1->destroyer->getY(), fleetPlayer1->destroyer->getOrientation());



			sf::Text text;
			text.setFont(font);
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::White);
			text.setPosition(20, 1100);
			text.setString("Hello World");
			window.draw(text);
			window.display();


			do
			{

				b1.fire(PLAYER1);

				window.clear();
				boardPlayer1.drawBoard(0, 0);
				boardViewPlayer1.drawBoard(11, 0);
				boardPlayer1.placeShip("Carrier", num2Char[fleetPlayer1->carrier->getX()], fleetPlayer1->carrier->getY(), fleetPlayer1->carrier->getOrientation());
				boardPlayer1.placeShip("Battleship", num2Char[fleetPlayer1->battleship->getX()], fleetPlayer1->battleship->getY(), fleetPlayer1->battleship->getOrientation());
				boardPlayer1.placeShip("Cruiser", num2Char[fleetPlayer1->cruiser->getX()], fleetPlayer1->cruiser->getY(), fleetPlayer1->cruiser->getOrientation());
				boardPlayer1.placeShip("Submarine", num2Char[fleetPlayer1->submarine->getX()], fleetPlayer1->submarine->getY(), fleetPlayer1->submarine->getOrientation());
				boardPlayer1.placeShip("Destroyer", num2Char[fleetPlayer1->destroyer->getX()], fleetPlayer1->destroyer->getY(), fleetPlayer1->destroyer->getOrientation());

				for (int i = 0; i < logPlayer1->x.size(); i++)
				{
					boardViewPlayer1.placeBomb(num2Char[logPlayer1->x[i]], logPlayer1->y[i]);
				}
				for (int i = 0; i < logPlayer2->x.size(); i++)
				{
					boardPlayer1.placeBomb(num2Char[logPlayer2->x[i]], logPlayer2->y[i]);
				}
				window.display();


				printf("\nPress any key to continue");
				scanf(" %c", &dummyChar);
				system("cls");

				b1.fire(PLAYER2);
				window.clear();
				boardPlayer1.drawBoard(0, 0);
				boardViewPlayer1.drawBoard(11, 0);
				boardPlayer1.placeShip("Carrier", num2Char[fleetPlayer1->carrier->getX()], fleetPlayer1->carrier->getY(), fleetPlayer1->carrier->getOrientation());
				boardPlayer1.placeShip("Battleship", num2Char[fleetPlayer1->battleship->getX()], fleetPlayer1->battleship->getY(), fleetPlayer1->battleship->getOrientation());
				boardPlayer1.placeShip("Cruiser", num2Char[fleetPlayer1->cruiser->getX()], fleetPlayer1->cruiser->getY(), fleetPlayer1->cruiser->getOrientation());
				boardPlayer1.placeShip("Submarine", num2Char[fleetPlayer1->submarine->getX()], fleetPlayer1->submarine->getY(), fleetPlayer1->submarine->getOrientation());
				boardPlayer1.placeShip("Destroyer", num2Char[fleetPlayer1->destroyer->getX()], fleetPlayer1->destroyer->getY(), fleetPlayer1->destroyer->getOrientation());

				for (int i = 0; i < logPlayer1->x.size(); i++)
				{
					boardViewPlayer1.placeBomb(num2Char[logPlayer1->x[i]], logPlayer1->y[i]);
				}
				for (int i = 0; i < logPlayer2->x.size(); i++)
				{
					boardPlayer1.placeBomb(num2Char[logPlayer2->x[i]], logPlayer2->y[i]);
				}
				window.display();


				printf("\nPress any key to continue");
				scanf(" %c", &dummyChar);
				system("cls");

			} while (b1.getStatusPlayer1() == b1.getStatusPlayer2());

			if (b1.getStatusPlayer1() == YES) // did player 1 loose?
			{
				printf("You lost!\n");
			}
			else
			{
				printf("you won!\n");
			}

		}

	}


private:
	board b1;

	logBook* logPlayer1;
	logBook* logPlayer2;

	fleet* fleetPlayer1;
	fleet* fleetPlayer2;

	char num2Char[10] = { 'A','B','C','D','E','F','G','H','I','J' };
	//					   0   1   2   3   4   5   6   7   8   9
};