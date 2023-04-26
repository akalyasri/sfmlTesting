#include "header.h"

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
