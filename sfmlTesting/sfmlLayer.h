#include "header.h"
#include <string>

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

	virtual void parseString(int* x, int* y, char shipType) //
	{
		cout << "take user input and parse it into x and y" << endl;
	}

	virtual void parseString2(int* x, int* y, char shipType)
	{
		cout << "take user input and parse it into x and y" << endl;
	}
};

class layer : public con2Sfml //polymorphism
{
public:
	layer()
	{

	}


	int yesNo() override //asks user for yes or no via popUp GUI
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

			sf::RenderWindow window(sf::VideoMode(1200, 200), "Invalid Coordinates");

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
							std::cout << "User entered: " << inputString << std::endl;
							return inputString;
							window.close();
						}
						else if (event.text.unicode == '\b') {
							if (!inputString.empty()) {
								inputString.pop_back();
								text.setString(inputString);
							}
						}
						else {
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

		if (type == 2) //out of bounds handle
		{
			sf::RenderWindow window(sf::VideoMode(1000, 200), "Out of Bounds!");

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
							std::cout << "User entered: " << inputString << std::endl;
							return inputString;
							window.close();
						}
						else if (event.text.unicode == '\b') {
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

		if (type == 7)
		{
			sf::RenderWindow window(sf::VideoMode(1000, 200), "Select a Rotation");

			sf::Font font;
			if (!font.loadFromFile("Fonts/ARIAL.ttf"))
			{
				std::cerr << "Error loading font file" << std::endl;
				return "-1";
			}

			sf::Text text;
			text.setFont(font);
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::White);

			sf::Text prompt;
			prompt.setFont(font);
			prompt.setCharacterSize(24);
			prompt.setFillColor(sf::Color::White);
			prompt.setString("Enter a choice of rotation (1-4):");

			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}

					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode >= '1' && event.text.unicode <= '4')
						{
							int index = event.text.unicode - '1';
							if (index >= 0 && index < strings.size())
							{
								text.setString(strings[index]);
								window.draw(text);
								window.display();

								sf::sleep(sf::seconds(2));
								return std::to_string(index);
								window.close();
							}
							else
							{
								prompt.setString("Invalid index. Enter another choice of rotation (1-4):");
							}
						}
						else
						{
							prompt.setString("Invalid input. Enter another choice of rotation (1-4):");
						}
					}
				}

				window.clear();


				for (int i = 0; i < strings.size(); ++i)
				{
					text.setString(strings[i]);
					text.setPosition(10, 50 + 30 * i);
					window.draw(text);
				}
				prompt.setPosition(10, 10);
				window.draw(prompt);

				window.display();
			}

			return "-1";
		}

		return "-1";
	}

	void parseString(int* x, int* y, char shipType) override //checking for coordinates that are already taken
	{
		string parString = enterCord(shipType);
		char xChar = parString[0];
		char yChar = parString[2];

		*x = xChar - '0';
		*y = yChar - '0';

	}

	void parseString2(int* x, int* y, char shipType) override //checking for coordinates that out of bounds
	{
		vector<string> dummy;
		string parString = inputCheck(1, dummy);

		char xChar = parString[0];
		char yChar = parString[2];

		*x = xChar - '0';
		*y = yChar - '0';
	}




private:
	string enterCord(char shipType) //asks user to enter in a coordinate for a specific ship
	{
		//string promptWindow = shipType + "Input Window";


		sf::RenderWindow window(sf::VideoMode(1000, 200), "Input Coordinates");

		sf::Font font;
		if (!font.loadFromFile("Fonts/ARIAL.ttf")) {
			std::cout << "Error loading font" << std::endl;
			return NULL;
		}

		sf::Text prompt;
		prompt.setFont(font);
		prompt.setCharacterSize(24);
		prompt.setFillColor(sf::Color::White);
		prompt.setString("Select a Coordinate (x y):");

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
						std::cout << "User entered: " << inputString << std::endl;
						return inputString;
						window.close();
					}
					else if (event.text.unicode == '\b') {
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


};
