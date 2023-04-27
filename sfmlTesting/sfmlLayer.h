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

	virtual void parseString(int* x, int* y, char shipType)
	{

	}

	virtual void parseString2(int* x, int* y, char shipType)
	{

	}
};

class layer : public con2Sfml //polymorphism
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

		if (type == 5)
		{
			// Define the array of strings
			//std::vector<std::string> strings = { "string1", "string2", "string3" };

			// Create the SFML window
			sf::RenderWindow window(sf::VideoMode(1000, 400), "String Array");

			// Create the SFML font object
			sf::Font font;
			if (!font.loadFromFile("Fonts/ARIAL.ttf"))
			{
				std::cerr << "Error loading font\n";
				return "-1";
			}

			// Create the SFML text object for displaying the strings
			sf::Text text("", font, 20);
			text.setFillColor(sf::Color::White);
			text.setPosition(10, 10);

			// Create the SFML text object for displaying the user prompt
			sf::Text prompt("Enter a choice of rotation:", font, 20);
			prompt.setFillColor(sf::Color::White);
			prompt.setPosition(10, 250);

			// Create the SFML text object for displaying the user input
			sf::Text input("", font, 20);
			input.setFillColor(sf::Color::White);
			input.setPosition(10, 280);

			// Main loop
			while (window.isOpen())
			{
				// Handle SFML events
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
					else if (event.type == sf::Event::TextEntered)
					{
						// If the user has typed a character
						if (event.text.unicode < 128)
						{
							// Append the character to the user input string
							input.setString(input.getString() + static_cast<char>(event.text.unicode));
						}
					}
					else if (event.type == sf::Event::KeyPressed)
					{
						// If the user has pressed the enter key
						if (event.key.code == sf::Keyboard::Enter)
						{
							// Try to convert the user input to an integer
							int choice = std::stoi(input.getString().toAnsiString());

							// If the choice is valid, return it and close the window
							if (choice >= 1 && choice <= strings.size())
							{
								std::cout << "Choice: " << choice << "\n";
								window.close();
							}
							// Otherwise, ask the user to input another number
							else
							{
								input.setString("");
							}
						}
					}
				}

				// Update the text object for displaying the strings
				std::string stringDisplay;
				for (const auto& str : strings)
				{
					stringDisplay += str + "\n";
				}
				text.setString(stringDisplay);

				// Clear the window
				window.clear();

				// Draw the text objects
				window.draw(text);
				window.draw(prompt);
				window.draw(input);

				// Display the window
				window.display();
			}

			return "-1";
		}

		if (type == 6)
		{
			// define the array of strings
			//std::string strArr[] = { "string1", "string2", "string3", "string4" };

			// create the SFML window
			sf::RenderWindow window(sf::VideoMode(1000, 300), "SFML Array of Strings");

			// create the SFML text object for displaying the strings
			sf::Font font;
			if (!font.loadFromFile("Fonts/ARIAL.ttf")) {
				std::cout << "Error loading font file\n";
				return 0;
			}
			sf::Text text("", font, 20);
			text.setPosition(50, 50);

			// create the SFML text object for the user input prompt
			sf::Text prompt("Enter a number for a choice of rotation (1-4):", font, 20);
			prompt.setPosition(50, 250);

			// the index of the selected string in the array (-1 means no selection)
			int selected = -1;

			// the main loop
			while (window.isOpen())
			{
				// handle events
				sf::Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
						// close the window when the close button is clicked
					case sf::Event::Closed:
						window.close();
						break;

						// handle key press events
					case sf::Event::KeyPressed:
						// if the user pressed a number key (1-4)
						if (event.key.code >= sf::Keyboard::Num1 && event.key.code <= sf::Keyboard::Num4) {
							int index = event.key.code - sf::Keyboard::Num1;
							// if the index corresponds to a string in the array, select it
							if (index >= 0 && index < sizeof(strings) / sizeof(strings[0])) {
								selected = index;
							}
							// if the index does not correspond to a string in the array, prompt the user to input another number
							else {
								text.setString("Invalid selection. Please enter a number from 1 to 4.");
								selected = -1;
							}
						}
						break;

						// handle text input events
					case sf::Event::TextEntered:
						// if the user entered a number key (1-4)
						if (event.text.unicode >= '1' && event.text.unicode <= '4') {
							int index = event.text.unicode - '1';
							// if the index corresponds to a string in the array, select it
							if (index >= 0 && index < sizeof(strings) / sizeof(strings[0])) {
								selected = index;
							}
							// if the index does not correspond to a string in the array, prompt the user to input another number
							else {
								text.setString("Invalid selection. Please enter a number from 1 to 4.");
								selected = -1;
							}
						}
						break;
					}
				}

				// if no string is selected, display the user input prompt
				if (selected == -1) {
					window.clear();
					window.draw(prompt);
				}
				// if a string is selected, display it and close the window
				else {
					text.setString(strings[selected]);
					window.clear(sf::Color::White);
					window.draw(text);
					window.display();
					sf::sleep(sf::seconds(1)); // wait for 1 second before closing the window
					window.close();
				}

				// display the window
				window.display();
			}

			// display the current selection
			if (selected != -1) {
				text.setString("Selected: " + strings[selected]);
				text.setPosition(50, 100);
				window.draw(text);
			}

			// display the window
			window.display();
		}

		if (type == 7)
		{
			// Create the window
			sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML window");

			// Define the vector of strings
			//std::vector<std::string> strings = { "string1", "string2", "string3", "string4" };

			// Create the text object for displaying the strings
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

			// Create the text object for prompting the user
			sf::Text prompt;
			prompt.setFont(font);
			prompt.setCharacterSize(24);
			prompt.setFillColor(sf::Color::White);
			prompt.setString("Enter a choice of rotation (1-4):");

			// Run the game loop
			while (window.isOpen())
			{
				// Handle events
				sf::Event event;
				while (window.pollEvent(event))
				{
					// Check for window closed
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}

					// Check for user input
					if (event.type == sf::Event::TextEntered)
					{
						// Check if the input is a number
						if (event.text.unicode >= '1' && event.text.unicode <= '4')
						{
							// Get the index from the input
							int index = event.text.unicode - '1';

							// Check if the index is within bounds
							if (index >= 0 && index < strings.size())
							{
								// Display the selected string
								text.setString(strings[index]);
								window.draw(text);
								window.display();

								// Wait for a moment before closing the window
								sf::sleep(sf::seconds(2));
								return std::to_string(index);
								window.close();
							}
							else
							{
								// Prompt the user to enter another number
								prompt.setString("Invalid index. Enter another choice of rotation (1-4):");
							}
						}
						else
						{
							// Prompt the user to enter another number
							prompt.setString("Invalid input. Enter another choice of rotation (1-4):");
						}
					}
				}

				// Clear the window
				window.clear();

				// Draw the strings and prompt
				for (int i = 0; i < strings.size(); ++i)
				{
					text.setString(strings[i]);
					text.setPosition(10, 50 + 30 * i);
					window.draw(text);
				}
				prompt.setPosition(10, 10);
				window.draw(prompt);

				// Display the window
				window.display();
			}

			return "-1";
		}

		return "-1";
	}

	void parseString(int* x, int* y, char shipType) override
	{
		string parString = enterCord(shipType);
		char xChar = parString[0];
		char yChar = parString[2];

		*x = xChar - '0';
		*y = yChar - '0';

	}

	void parseString2(int* x, int* y, char shipType) override
	{
		vector<string> dummy;
		string parString = inputCheck(1, dummy);

		char xChar = parString[0];
		char yChar = parString[2];

		*x = xChar - '0';
		*y = yChar - '0';
	}




private:
	string enterCord(char shipType)
	{
		string promptWindow = shipType + "Input Window";


		sf::RenderWindow window(sf::VideoMode(1000, 200), promptWindow);

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
	}


};
//std::cout << "Pick the first coordinate to place your " << shipType << "User input (x y): " << inputText.getString().toAnsiString() << std::endl;