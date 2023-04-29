#include "header.h"
#include "ships.h"
#include "sfmlLayer.h"

const sf::RenderWindow& gameWindow2 = sf::RenderWindow(sf::VideoMode(880 * 2, 1200), "Game Board!");


sf::RenderWindow& gameWindow = const_cast<sf::RenderWindow&>(gameWindow2);

void getMouseInput(int& xCoord, int& yCoord) {

	while (gameWindow.isOpen()) {

		sf::Event event;

		while (gameWindow.pollEvent(event)) {

			if (event.type == sf::Event::MouseButtonPressed) {

				//window == 1680 x 1200

				sf::Vector2i mousePos = sf::Mouse::getPosition(gameWindow);

				if (mousePos.x <= 160 && mousePos.x > 80 || mousePos.x <= 1760 && mousePos.x > 1680) {
					xCoord = 9;
				}
				else if ((mousePos.x <= 240 && mousePos.x > 160) || (mousePos.x <= 1040 && mousePos.x > 960)) {
					xCoord = 0;
				}
				else if ((mousePos.x <= 320 && mousePos.x > 240) || (mousePos.x <= 1120 && mousePos.x > 1040)) {
					xCoord = 1;
				}
				else if ((mousePos.x <= 400 && mousePos.x > 320) || (mousePos.x <= 1200 && mousePos.x > 1120)) {
					xCoord = 2;
				}
				else if ((mousePos.x <= 480 && mousePos.x > 400) || (mousePos.x <= 1280 && mousePos.x > 1200)) {
					xCoord = 3;
				}
				else if ((mousePos.x <= 560 && mousePos.x > 480) || (mousePos.x <= 1360 && mousePos.x > 1280)) {
					xCoord = 4;
				}
				else if ((mousePos.x <= 640 && mousePos.x > 560) || (mousePos.x <= 1440 && mousePos.x > 1360)) {
					xCoord = 5;
				}
				else if ((mousePos.x <= 720 && mousePos.x > 640) || (mousePos.x <= 1520 && mousePos.x > 1440)) {
					xCoord = 6;
				}
				else if ((mousePos.x <= 800 && mousePos.x > 720) || (mousePos.x <= 1600 && mousePos.x > 1520)) {
					xCoord = 7;
				}
				else if ((mousePos.x <= 880 && mousePos.x > 800) || (mousePos.x <= 1680 && mousePos.x > 1600)) {
					xCoord = 8;
				}


				//Find Y position
				/*if (mousePos.y <= 1120 && mousePos.y > 1040) {
					yCoord = 2;
				}
				else if (mousePos.y <= 1040 && mousePos.y > 960) {
					yCoord = 1;
				}
				else if (mousePos.y <= 960 && mousePos.y > 880) {
					yCoord = 0;
				}
				else */if (mousePos.y <= 880 && mousePos.y > 800) {
					yCoord = 9;
				}
				else if (mousePos.y <= 800 && mousePos.y > 720) {
					yCoord = 8;
				}
				else if (mousePos.y <= 720 && mousePos.y > 640) {
					yCoord = 7;
				}
				else if (mousePos.y <= 640 && mousePos.y > 560) {
					yCoord = 6;
				}
				else if (mousePos.y <= 560 && mousePos.y > 480) {
					yCoord = 5;
				}
				else if (mousePos.y <= 480 && mousePos.y > 400) {
					yCoord = 4;
				}
				else if (mousePos.y <= 400 && mousePos.y > 320) {
					yCoord = 3;
				}
				else if (mousePos.y <= 320 && mousePos.y > 240) {
					yCoord = 2;
				}
				else if (mousePos.y <= 240 && mousePos.y > 160) {
					yCoord = 1;
				}
				else if (mousePos.y <= 160 && mousePos.y > 80) {
					yCoord = 0;
				}


				//double mouseX = sf::Mouse::getPosition(gameWindow).x*(gameWindow.getDefaultView().getSize().x/gameWindow.x)

				return;


			}


		}

	}

}


class board
{
public:

	board() {
		status[0] = NSUNK;
		status[1] = NSUNK;

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


	/*board(sf::RenderWindow& window) : gameWindow(window){

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
	}*/

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
		int x = 0;
		int y = 0;

		int hpLeft = 0;

		int& userXCoord = x;
		int& userYCoord = y;
		//getMouseInput(userXCoord, userYCoord);

		//int x = 0, y = 0;
		char shipHit = '\0';
		int tryAgain = YES;
		int win = NO;

		if (whoPlay == PLAYER1) // PLAYER 1 game
		{
			//printf("Type in the coordeinate to fire (X Y) ");
			//scanf("%d %d", &x, &y);
			getMouseInput(userXCoord, userYCoord);
			while (tryAgain == YES)
			{
				while (tryAgain == YES)
				{
					if (x > 9 && x < 0 && y > 9 && y < 0)
					{
						printf("\nYour X or Y is out of bounds (0 <= x <= 9) (0 <= y <= 9): ");
						//scanf("%d %d", &x, &y);
						getMouseInput(userXCoord, userYCoord);
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
						//scanf("%d %d", &x, &y);
						getMouseInput(userXCoord, userYCoord);
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
				fireSound(HIT);

				boardViewPlayer1[y][x] = 'o';
				boardPlayer2[y][x] = 'o';


				logPlayer1.x.push_back(x); //keeps track of shots
				logPlayer1.y.push_back(y);


			}
			else
			{
				if (fleetPlayer2.carrier->getIdentification() == boardPlayer2[y][x]) {

					

					printf("You hit carrier\n");
					fireSound(HIT);

					//fprintf(infile, "Player has scored a hit on the carrier || Coordinate: (%d,%d)\n ", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.carrier->setHP(fleetPlayer2.carrier->getHP() - 1);
					if (fleetPlayer2.carrier->getHP() == hpLeft)
					{
						printf("You sunk carrier\n");
						//fprintf(infile, "Player has sunk the carrier || Coordinate: (%d,%d)\n", x, y);
						//playerCarrier->sunk = YES;
						fleetPlayer2.carrier->setSunk(SUNK);
					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else if (fleetPlayer2.battleship->getIdentification() == boardPlayer2[y][x])
				{
					printf("You hit battleship\n");
					fireSound(HIT);

					//fprintf(infile, "Player has scored a hit on the battleship || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.battleship->setHP(fleetPlayer2.battleship->getHP() - 1);
					if (fleetPlayer2.battleship->getHP() == hpLeft)
					{
						printf("You sunk battleship\n");
						//fprintf(infile, "Player has sunk the battleship || Coordinate: (%d,%d)\n", x, y);
						//playerBattleship->sunk = YES;
						fleetPlayer2.battleship->setSunk(SUNK);

					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else if (fleetPlayer2.cruiser->getIdentification() == boardPlayer2[y][x])
				{
					printf("You hit cruiser\n");
					fireSound(HIT);

					//fprintf(infile, "Player has scored a hit on the cruiser || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.cruiser->setHP(fleetPlayer2.cruiser->getHP() - 1);
					if (fleetPlayer2.cruiser->getHP() == hpLeft)
					{
						printf("You sunk cruiser\n");
						//fprintf(infile, "Player has sunkt the cruiser || Coordinate: (%d,%d)\n", x, y);
						//playerCruiser->sunk = YES;
						fleetPlayer2.cruiser->setSunk(SUNK);

					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else if (fleetPlayer2.submarine->getIdentification() == boardPlayer2[y][x])
				{
					printf("You hit submarine\n");
					fireSound(HIT);

					//fprintf(infile, "Player has scored a hit on the submarine || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.submarine->setHP(fleetPlayer2.submarine->getHP() - 1);
					if (fleetPlayer2.submarine->getHP() == hpLeft)
					{
						printf("You sunk submarine\n");
						//fprintf(infile, "Player has sunk the submarine || Coordinate: (%d,%d)\n", x, y);
						//playerSubmarine->sunk = YES;
						fleetPlayer2.submarine->setSunk(SUNK);

					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else if (fleetPlayer1.destroyer->getIdentification() == boardPlayer2[y][x])
				{
					printf("You hit destroyer\n");
					fireSound(HIT);

					//fprintf(infile, "Player has scored a hit on the destroyer || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer1[y][x] = 'x';
					boardPlayer2[y][x] = 'x';
					fleetPlayer2.destroyer->setHP(fleetPlayer2.destroyer->getHP() - 1);
					if (fleetPlayer2.destroyer->getHP() == hpLeft)
					{
						printf("You sunk destroyer\n");
						//fprintf(infile, "Player has sunk the destroyer || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer2.destroyer->setSunk(SUNK);

					}

					logPlayer1.x.push_back(x); //keeps track of shots
					logPlayer1.y.push_back(y);
				}
				else
				{
					//printf("\nSomething is wrong with your code"); // debug code
				}

				if ((fleetPlayer2.carrier->getSunk() == SUNK) && (fleetPlayer2.battleship->getSunk() == SUNK) && (fleetPlayer2.cruiser->getSunk() == SUNK) && (fleetPlayer2.submarine->getSunk() == SUNK) && (fleetPlayer2.destroyer->getSunk() == SUNK))
				{
					//cout << "Player Has Won!" << endl;
					status[1] = SUNK;
					//fprintf(infile, "Player has won! \n");

				}
			}


		}
		else
		{
			x = rand() % 10 + 0;
			y = rand() % 10 + 0;

			while (tryAgain == YES)
			{
				while (tryAgain == YES)
				{
					if (x > 9 && x < 0 && y > 9 && y < 0 && boardViewPlayer2[y][x] == 'o' && boardViewPlayer2[y][x] == 'x')
					{
						x = rand() % 10 + 0;
						y = rand() % 10 + 0;
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
				fireSound(MISS);

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
					fireSound(HIT);

					//fprintf(infile, "Computer has scored a hit on the carrier || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerCarrier->hit--;
					fleetPlayer1.carrier->setHP(fleetPlayer1.carrier->getHP() - 1);
					if (fleetPlayer1.carrier->getHP() == hpLeft)
					{
						printf("Computer sunk carrier\n");
						//fprintf(infile, "Computer has sunk the carrier || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.carrier->setSunk(SUNK);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);
				}
				else if (fleetPlayer1.battleship->getIdentification() == boardPlayer1[y][x])
				{
					printf("Computer hit battleship \n");
					fireSound(HIT);

					//fprintf(infile, "Computer has scored a hit on the battleship || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerBattleship->hit--;
					fleetPlayer1.battleship->setHP(fleetPlayer1.battleship->getHP() - 1);
					if (fleetPlayer1.battleship->getHP() == hpLeft)
					{
						printf("Computer sunk battleship\n");
						//fprintf(infile, "Computer has sunk the battleship || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.battleship->setSunk(SUNK);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);

				}
				else if (fleetPlayer1.cruiser->getIdentification() == boardPlayer1[y][x])
				{
					printf("Computer hit cruiser\n");
					fireSound(HIT);

					//fprintf(infile, "Computer has scored a hit on the cruiser || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerCruiser->hit--;
					fleetPlayer1.cruiser->setHP(fleetPlayer1.cruiser->getHP() - 1);
					if (fleetPlayer1.cruiser->getHP() == hpLeft)
					{
						printf("Computer sunk cruiser\n");
						//fprintf(infile, "Computer has sunk the cruiser || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.cruiser->setSunk(SUNK);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);
				}
				else if (fleetPlayer1.submarine->getIdentification() == boardPlayer1[y][x])
				{
					printf("Computer hit submarine\n");
					fireSound(HIT);

					//fprintf(infile, "Computer has scored a hit on the submarine || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerSubmarine->hit--;
					fleetPlayer1.submarine->setHP(fleetPlayer1.submarine->getHP() - 1);
					if (fleetPlayer1.submarine->getHP() == hpLeft)
					{
						printf("Computer sunk submarine\n");
						//fprintf(infile, "Computer has sunk the submarine || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.submarine->setSunk(SUNK);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);
				}
				else if (fleetPlayer1.destroyer->getIdentification() == boardPlayer1[y][x])
				{
					printf("Computer hit destroyer \n");
					fireSound(HIT);

					//fprintf(infile, "Computer has scored a hit on the destroyer || Coordinate: (%d,%d)\n", x, y);
					boardViewPlayer2[y][x] = 'x';
					boardPlayer1[y][x] = 'x';
					//playerDestroyer->hit--;
					fleetPlayer1.destroyer->setHP(fleetPlayer1.destroyer->getHP() - 1);
					if (fleetPlayer1.destroyer->getHP() == hpLeft)
					{
						printf("Computer sunk destroyer\n");
						//fprintf(infile, "Computer has sunk the destroyer || Coordinate: (%d,%d)\n", x, y);
						fleetPlayer1.destroyer->setSunk(SUNK);

					}

					logPlayer2.x.push_back(x); //keeps track of shots
					logPlayer2.y.push_back(y);
				}
				else
				{
					printf("\n CPU Something is wrong with your code");
				}

				if ((fleetPlayer1.carrier->getSunk() == SUNK) && (fleetPlayer1.battleship->getSunk() == SUNK) && (fleetPlayer1.cruiser->getSunk() == SUNK) && (fleetPlayer1.submarine->getSunk() == SUNK) && (fleetPlayer1.destroyer->getSunk() == SUNK))
				{
					//cout << "Computer Has Won" << endl;
					status[0] = SUNK;
					//fprintf(infile, "Computer has won!\n");

				}

			}



		}

	}

	/*
	void placeShipNUL(int whoPlay)
	{
		con2Sfml* sfmlLayer = new layer;

		int x = 0;
		int y = 0;

		int& userXCoord = x;
		int& userYCoord = y;


		if (whoPlay == PLAYER1)
		{
			if (sfmlLayer->yesNo() == 0) // manually place ships
			{

				//							MOUSE INPUT
				//////////////////////////////////////////////////////////////////////////////

				getMouseInput(userXCoord, userYCoord);



				//printf("Pick the first coordinate to place your carrier (X Y): ");
				placeMan(boardPlayer1, 4, fleetPlayer1.carrier->getIdentification(), fleetPlayer1, x, y);
				system("cls");
				printBoard(PLAYER1);

				//printf("Pick the first coordinate to place your battleship (X Y): ");
				placeMan(boardPlayer1, 3, fleetPlayer1.battleship->getIdentification(), fleetPlayer1, x, y);
				system("cls");
				printBoard(PLAYER1);

				//printf("Pick the first coordinate to place your cruiser (X Y): ");
				placeMan(boardPlayer1, 2, fleetPlayer1.cruiser->getIdentification(), fleetPlayer1, x, y);
				system("cls");
				printBoard(PLAYER1);

				//printf("Pick the first coordinate to place your submarine (X Y): ");
				placeMan(boardPlayer1, 2, fleetPlayer1.submarine->getIdentification(), fleetPlayer1, x, y);
				system("cls");
				printBoard(PLAYER1);

				//printf("Pick the first coordinate to place your destroyer (X Y): ");
				placeMan(boardPlayer1, 1, fleetPlayer1.destroyer->getIdentification(), fleetPlayer1, x, y);
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
	*/
	//old placeShip function

	void placeShip(int whoPlay)
	{
		con2Sfml* sfmlLayer = new layer;

		if (whoPlay == PLAYER1)
		{
			if (sfmlLayer->yesNo() == 0) // manually place ships
			{
				sf::RenderWindow window(sf::VideoMode(880 * 2, 1200), "Game Board!");
				//sf::Style::Resize
				Board boardPlayer1GUI(window);
				Board boardViewPlayer1GUI(window);
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


					window.clear();
					boardPlayer1GUI.drawBoard(0, 0);
					boardViewPlayer1GUI.drawBoard(11, 0);
					window.display();

					//printf("Pick the first coordinate to place your carrier (X Y): ");
					placeMan(boardPlayer1, 4, fleetPlayer1.carrier->getIdentification(), fleetPlayer1);
					system("cls");
					printBoard(PLAYER1);

					window.clear();
					boardPlayer1GUI.drawBoard(0, 0);
					boardViewPlayer1GUI.drawBoard(11, 0);
					boardPlayer1GUI.placeShip("Carrier", num2Char[fleetPlayer1.carrier->getX()], fleetPlayer1.carrier->getY(), fleetPlayer1.carrier->getOrientation());
					window.display();


					//printf("Pick the first coordinate to place your battleship (X Y): ");
					placeMan(boardPlayer1, 3, fleetPlayer1.battleship->getIdentification(), fleetPlayer1);
					system("cls");
					printBoard(PLAYER1);

					window.clear();
					boardPlayer1GUI.drawBoard(0, 0);
					boardViewPlayer1GUI.drawBoard(11, 0);
					boardPlayer1GUI.placeShip("Carrier", num2Char[fleetPlayer1.carrier->getX()], fleetPlayer1.carrier->getY(), fleetPlayer1.carrier->getOrientation());
					boardPlayer1GUI.placeShip("Battleship", num2Char[fleetPlayer1.battleship->getX()], fleetPlayer1.battleship->getY(), fleetPlayer1.battleship->getOrientation());
					window.display();


					//printf("Pick the first coordinate to place your cruiser (X Y): ");
					placeMan(boardPlayer1, 2, fleetPlayer1.cruiser->getIdentification(), fleetPlayer1);
					system("cls");
					printBoard(PLAYER1);

					window.clear();
					boardPlayer1GUI.drawBoard(0, 0);
					boardViewPlayer1GUI.drawBoard(11, 0);

					boardPlayer1GUI.placeShip("Carrier", num2Char[fleetPlayer1.carrier->getX()], fleetPlayer1.carrier->getY(), fleetPlayer1.carrier->getOrientation());
					boardPlayer1GUI.placeShip("Battleship", num2Char[fleetPlayer1.battleship->getX()], fleetPlayer1.battleship->getY(), fleetPlayer1.battleship->getOrientation());
					boardPlayer1GUI.placeShip("Cruiser", num2Char[fleetPlayer1.cruiser->getX()], fleetPlayer1.cruiser->getY(), fleetPlayer1.cruiser->getOrientation());
					window.display();


					//printf("Pick the first coordinate to place your submarine (X Y): ");
					placeMan(boardPlayer1, 2, fleetPlayer1.submarine->getIdentification(), fleetPlayer1);
					system("cls");
					printBoard(PLAYER1);

					window.clear();
					boardPlayer1GUI.drawBoard(0, 0);
					boardViewPlayer1GUI.drawBoard(11, 0);
					boardPlayer1GUI.placeShip("Carrier", num2Char[fleetPlayer1.carrier->getX()], fleetPlayer1.carrier->getY(), fleetPlayer1.carrier->getOrientation());
					boardPlayer1GUI.placeShip("Battleship", num2Char[fleetPlayer1.battleship->getX()], fleetPlayer1.battleship->getY(), fleetPlayer1.battleship->getOrientation());
					boardPlayer1GUI.placeShip("Cruiser", num2Char[fleetPlayer1.cruiser->getX()], fleetPlayer1.cruiser->getY(), fleetPlayer1.cruiser->getOrientation());
					boardPlayer1GUI.placeShip("Submarine", num2Char[fleetPlayer1.submarine->getX()], fleetPlayer1.submarine->getY(), fleetPlayer1.submarine->getOrientation());
					window.display();


					//printf("Pick the first coordinate to place your destroyer (X Y): ");
					placeMan(boardPlayer1, 1, fleetPlayer1.destroyer->getIdentification(), fleetPlayer1);
					system("cls");
					//print_board(board, 10, 10);

					window.clear();
					boardPlayer1GUI.drawBoard(0, 0);
					boardViewPlayer1GUI.drawBoard(11, 0);
					boardPlayer1GUI.placeShip("Carrier", num2Char[fleetPlayer1.carrier->getX()], fleetPlayer1.carrier->getY(), fleetPlayer1.carrier->getOrientation());
					boardPlayer1GUI.placeShip("Battleship", num2Char[fleetPlayer1.battleship->getX()], fleetPlayer1.battleship->getY(), fleetPlayer1.battleship->getOrientation());
					boardPlayer1GUI.placeShip("Cruiser", num2Char[fleetPlayer1.cruiser->getX()], fleetPlayer1.cruiser->getY(), fleetPlayer1.cruiser->getOrientation());
					boardPlayer1GUI.placeShip("Submarine", num2Char[fleetPlayer1.submarine->getX()], fleetPlayer1.submarine->getY(), fleetPlayer1.submarine->getOrientation());
					boardPlayer1GUI.placeShip("Destroyer", num2Char[fleetPlayer1.submarine->getX()], fleetPlayer1.submarine->getY(), fleetPlayer1.submarine->getOrientation());
					window.display();

					window.close();

				}


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

	int status[2];
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

	//int status[2] = { NSUNK,NSUNK };

	int infoX;
	int infoY;
	int infoRotation;

	char num2Char[10] = { 'A','B','C','D','E','F','G','H','I','J' };
	//					   0   1   2   3   4   5   6   7   8   9


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

	friend class game;


	/*void placeMan(char board[][10], int size, char identification, class fleet& ref, int xRef, int yRef)*/

	void placeManNUL(char board[][10], int size, char identification, class fleet& ref)
	{
		int x = 0, y;
		int placeable = YES;
		int rotation[4] = { 0 };
		// left, right, down, up

		int choice = 0;
		vector<string> rotateString;

		// scanf("%d %d", &x, &y); 
		inputCheck(1, board, &x, &y, rotation, &choice, rotateString, identification); // x and y input



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
			//printf("1) You can rotate left\n");
			rotateString.push_back("1) You can rotate left");
		}
		else
		{
			rotateString.push_back("\0");
		}

		if (rotation[1] == 1)
		{
			//printf("2) You can rotate right\n");
			rotateString.push_back("2) You can rotate right");
		}
		else
		{
			rotateString.push_back("\0");
		}

		if (rotation[2] == 1)
		{
			//printf("3) You can rotate down\n");
			rotateString.push_back("3) You can rotate down");
		}
		else
		{
			rotateString.push_back("\0");
		}

		if (rotation[3] == 1)
		{
			//printf("4) You can roate up\n");
			rotateString.push_back("4) You can roate up");
		}
		else
		{
			rotateString.push_back("\0");
		}

		// what if no roations were found? Put in check code

		//printf("What would you like to do? Pick the corresponding number: ");
		//scanf("%d", &choice);
		inputCheck(2, board, &x, &y, rotation, &choice, rotateString, identification); // rotation choice input

		int uRot = 0;

		switch (++choice)
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
	void inputCheckNUL(int checkType, char board[][10], int* x, int* y, int rotation[], int* choice, vector<string> rotationString, char shipType)
	{
		int tryAgain = YES;
		con2Sfml* sfmlLayer = new layer;

		if (checkType == 1)
		{
			//scanf("%d %d", x, y);
			//sfmlLayer->parseString(x, y, shipType);
			while (tryAgain == YES)
			{
				if (board[*y][*x] != '~')
				{
					/*printf("\nYou picked a coordinate that has already been taken by other ship\n Select a different coordinate: ");
					scanf("%d %d", x, y);*/

					//sfmlLayer->inputCheck(1, rotationString);

					sfmlLayer->parseString2(x, y, shipType);

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
			//scanf("%d", choice);
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

			* choice = stoi(sfmlLayer->inputCheck(7, rotationString));
			//*choice++;

		}
	}

	void placeMan(char board[][10], int size, char identification, class fleet& ref)
	{
		int x = 0, y = 0;
		int placeable = YES;
		int rotation[4] = { 0 };
		// left, right, down, up

		int choice = 0;
		vector<string> rotateString;

		// scanf("%d %d", &x, &y); 
		inputCheck(1, board, &x, &y, rotation, &choice, rotateString, identification); // x and y input



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
			//printf("1) You can rotate left\n");
			rotateString.push_back("1) You can rotate left");
		}
		else
		{
			rotateString.push_back("\0");
		}

		if (rotation[1] == 1)
		{
			//printf("2) You can rotate right\n");
			rotateString.push_back("2) You can rotate right");
		}
		else
		{
			rotateString.push_back("\0");
		}

		if (rotation[2] == 1)
		{
			//printf("3) You can rotate down\n");
			rotateString.push_back("3) You can rotate down");
		}
		else
		{
			rotateString.push_back("\0");
		}

		if (rotation[3] == 1)
		{
			//printf("4) You can roate up\n");
			rotateString.push_back("4) You can roate up");
		}
		else
		{
			rotateString.push_back("\0");
		}

		// what if no roations were found? Put in check code

		//printf("What would you like to do? Pick the corresponding number: ");
		//scanf("%d", &choice);
		inputCheck(2, board, &x, &y, rotation, &choice, rotateString, identification); // rotation choice input

		int uRot = 0;

		switch (++choice)
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
	void inputCheck(int checkType, char board[][10], int* x, int* y, int rotation[], int* choice, vector<string> rotationString, char shipType)
	{
		int tryAgain = YES;
		con2Sfml* sfmlLayer = new layer;

		if (checkType == 1)
		{
			//scanf("%d %d", x, y);
			sfmlLayer->parseString(x, y, shipType);
			while (tryAgain == YES)
			{
				if (board[*y][*x] != '~')
				{
					/*printf("\nYou picked a coordinate that has already been taken by other ship\n Select a different coordinate: ");
					scanf("%d %d", x, y);*/


					sfmlLayer->parseString2(x, y, shipType);

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
			//scanf("%d", choice);
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

			* choice = stoi(sfmlLayer->inputCheck(7, rotationString));

		}
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
			*x = rand() % 10 + 0;
			*y = rand() % 10 + 0;

			while (tryAgain == YES)
			{
				if (board[*y][*x] != '~')
				{
					//printf("\nYou picked a coordinate that has already been taken by other ship\n Select a different coordinate: ");
					*x = rand() % 10 + 0;
					*y = rand() % 10 + 0;

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


	void fireSound(int type)
	{
		sf::SoundBuffer buffer;
		sf::Sound sound;
		sound.setBuffer(buffer);
		sound.play();

		if (type == HIT)
		{

			if (!buffer.loadFromFile("sound/bomb.wav"))
			{

			}
			sound.setBuffer(buffer);
			sound.play();

			//return -1;

		}
		else if (type == MISS)
		{

			if (!buffer.loadFromFile("sound/splash.flac"))
			{

			}
			sound.setBuffer(buffer);
			sound.play();
			//return -1;

		}
	}

	//sf::RenderWindow& gameWindow;

};

class game
{
public:

	game() {
		//constructor
	}



	void getMouseInput(int& xCoord, int& yCoord) {

		while (gameWindow.isOpen()) {

			sf::Event event;

			while (gameWindow.pollEvent(event)) {

				if (event.type == sf::Event::MouseButtonPressed) {

					//window == 1680 x 1200

					sf::Vector2i mousePos = sf::Mouse::getPosition(gameWindow);

					if (mousePos.x <= 160 && mousePos.x > 80) {
						xCoord = 0;
					}
					else if ((mousePos.x <= 240 && mousePos.x > 160) || (mousePos.x <= 1040 && mousePos.x > 960)) {
						xCoord = 1;
					}
					else if ((mousePos.x <= 320 && mousePos.x > 240) || (mousePos.x <= 1120 && mousePos.x > 1040)) {
						xCoord = 2;
					}
					else if ((mousePos.x <= 400 && mousePos.x > 320) || (mousePos.x <= 1200 && mousePos.x > 1120)) {
						xCoord = 3;
					}
					else if ((mousePos.x <= 480 && mousePos.x > 400) || (mousePos.x <= 1280 && mousePos.x > 1200)) {
						xCoord = 4;
					}
					else if ((mousePos.x <= 560 && mousePos.x > 480) || (mousePos.x <= 1360 && mousePos.x > 1280)) {
						xCoord = 5;
					}
					else if ((mousePos.x <= 640 && mousePos.x > 560) || (mousePos.x <= 1440 && mousePos.x > 1360)) {
						xCoord = 6;
					}
					else if ((mousePos.x <= 720 && mousePos.x > 640) || (mousePos.x <= 1520 && mousePos.x > 1440)) {
						xCoord = 7;
					}
					else if ((mousePos.x <= 800 && mousePos.x > 720) || (mousePos.x <= 1600 && mousePos.x > 1520)) {
						xCoord = 8;
					}
					else if ((mousePos.x <= 880 && mousePos.x > 800) || (mousePos.x <= 1680 && mousePos.x > 1600)) {
						xCoord = 9;
					}



					if (mousePos.y <= 1120 && mousePos.y > 1040) {
						yCoord = 0;
					}
					else if (mousePos.y <= 1040 && mousePos.y > 960) {
						yCoord = 1;
					}
					else if (mousePos.y <= 960 && mousePos.y > 880) {
						yCoord = 2;
					}
					else if (mousePos.y <= 880 && mousePos.y > 800) {
						yCoord = 3;
					}
					else if (mousePos.y <= 800 && mousePos.y > 720) {
						yCoord = 4;
					}
					else if (mousePos.y <= 720 && mousePos.y > 640) {
						yCoord = 5;
					}
					else if (mousePos.y <= 640 && mousePos.y > 560) {
						yCoord = 6;
					}
					else if (mousePos.y <= 560 && mousePos.y > 480) {
						yCoord = 7;
					}
					else if (mousePos.y <= 480 && mousePos.y > 400) {
						yCoord = 8;
					}
					else if (mousePos.y <= 400 && mousePos.y > 320) {
						yCoord = 9;
					}


					return;


				}


			}

		}

	}


	/*
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
			if (type == 0) // manually

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
			else if (type == 1) //
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

	*/


	void runGame()
	{
		b1.placeShip(PLAYER1);
		b1.placeShip(PLAYER2);
		logPlayer1 = b1.getLogPlayer1(); //vector
		logPlayer2 = b1.getLogPlayer2();

		//////////////////////////////////////////////////////////////// IMPORTANT!! GIVES ACCESS TO SHIP COORDINATES AND SHOTS FIRED
		fleetPlayer1 = b1.getFleetPlayer1();
		fleetPlayer2 = b1.getFleetPlayer2();
		//////////////////////////////////////////////////////////////// To access ship info go to fleetPlayer->shipName->get____ ||to access shots fired history go to logPlayer1->x.__



		//sf::RenderWindow window(sf::VideoMode(880 * 2, 1200), "Game Board!");
		//sf::Style::Resize
		Board boardPlayer1(gameWindow);
		Board boardViewPlayer1(gameWindow);


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

			char dummyChar = '\0';
			//b1.printBoard(BOARDPLAYER1);
			//b1.placeShip(PLAYER1);

			// Placing ships on computer's board
			//b1.placeShip(PLAYER2);
			//printf("Computer Board\n"); // debug code, speeds up testing of game
			b1.printBoard(BOARDPLAYER2);


			int adjust = 0;

			gameWindow.clear();
			boardPlayer1.drawBoard(0, 0);
			boardViewPlayer1.drawBoard(11, 0);

			/*cout << "Carrier (" << fleetPlayer1->carrier->getX() << ", " << fleetPlayer1->carrier->getY() << ")" << "Rotation: " << fleetPlayer1->carrier->getOrientation() << endl;
			cout << "Battleship (" << fleetPlayer1->battleship->getX() << ", " << fleetPlayer1->battleship->getY() << ")" << "Rotation: " << fleetPlayer1->battleship->getOrientation() << endl;
			cout << "Cruiser (" << fleetPlayer1->cruiser->getX() << ", " << fleetPlayer1->cruiser->getY() << ")" << "Rotation: " << fleetPlayer1->cruiser->getOrientation() << endl;
			cout << "Submarine (" << fleetPlayer1->submarine->getX() << ", " << fleetPlayer1->submarine->getY() << ")" << "Rotation: " << fleetPlayer1->submarine->getOrientation() << endl;
			cout << "Destroyer (" << fleetPlayer1->destroyer->getX() << ", " << fleetPlayer1->destroyer->getY() << ")" << "Rotation: " << fleetPlayer1->destroyer->getOrientation() << endl;*/



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
			gameWindow.draw(text);
			gameWindow.display(); //


			do
			{

				b1.fire(PLAYER1);

				gameWindow.clear();
				boardPlayer1.drawBoard(0, 0);
				boardViewPlayer1.drawBoard(11, 0);
				boardPlayer1.placeShip("Carrier", num2Char[fleetPlayer1->carrier->getX()], fleetPlayer1->carrier->getY(), fleetPlayer1->carrier->getOrientation());
				boardPlayer1.placeShip("Battleship", num2Char[fleetPlayer1->battleship->getX()], fleetPlayer1->battleship->getY(), fleetPlayer1->battleship->getOrientation());
				boardPlayer1.placeShip("Cruiser", num2Char[fleetPlayer1->cruiser->getX()], fleetPlayer1->cruiser->getY(), fleetPlayer1->cruiser->getOrientation());
				boardPlayer1.placeShip("Submarine", num2Char[fleetPlayer1->submarine->getX()], fleetPlayer1->submarine->getY(), fleetPlayer1->submarine->getOrientation());
				boardPlayer1.placeShip("Destroyer", num2Char[fleetPlayer1->destroyer->getX()], fleetPlayer1->destroyer->getY(), fleetPlayer1->destroyer->getOrientation());

				if (fleetPlayer2->carrier->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Carrier", num2Char[fleetPlayer2->carrier->getX()], fleetPlayer2->carrier->getY(), fleetPlayer2->carrier->getOrientation());
				}
				if (fleetPlayer2->battleship->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Battleship", num2Char[fleetPlayer2->battleship->getX()], fleetPlayer2->battleship->getY(), fleetPlayer2->battleship->getOrientation());
				}
				if (fleetPlayer2->cruiser->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Cruiser", num2Char[fleetPlayer2->cruiser->getX()], fleetPlayer2->cruiser->getY(), fleetPlayer2->cruiser->getOrientation());
				}
				if (fleetPlayer2->submarine->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Submarine", num2Char[fleetPlayer2->submarine->getX()], fleetPlayer2->submarine->getY(), fleetPlayer2->submarine->getOrientation());
				}
				if (fleetPlayer2->destroyer->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Destroyer", num2Char[fleetPlayer2->destroyer->getX()], fleetPlayer2->destroyer->getY(), fleetPlayer2->destroyer->getOrientation());
				}

				for (int i = 0; i < logPlayer1->x.size(); i++)
				{
					boardViewPlayer1.placeBomb(num2Char[logPlayer1->x[i]], logPlayer1->y[i]);
				}
				for (int i = 0; i < logPlayer2->x.size(); i++)
				{
					boardPlayer1.placeBomb(num2Char[logPlayer2->x[i]], logPlayer2->y[i]);
				}
				gameWindow.display();


				//printf("\nPress any key to continue");
				//scanf(" %c", &dummyChar);
				//system("cls");

				b1.fire(PLAYER2);
				gameWindow.clear();
				boardPlayer1.drawBoard(0, 0);
				boardViewPlayer1.drawBoard(11, 0);
				boardPlayer1.placeShip("Carrier", num2Char[fleetPlayer1->carrier->getX()], fleetPlayer1->carrier->getY(), fleetPlayer1->carrier->getOrientation());
				boardPlayer1.placeShip("Battleship", num2Char[fleetPlayer1->battleship->getX()], fleetPlayer1->battleship->getY(), fleetPlayer1->battleship->getOrientation());
				boardPlayer1.placeShip("Cruiser", num2Char[fleetPlayer1->cruiser->getX()], fleetPlayer1->cruiser->getY(), fleetPlayer1->cruiser->getOrientation());
				boardPlayer1.placeShip("Submarine", num2Char[fleetPlayer1->submarine->getX()], fleetPlayer1->submarine->getY(), fleetPlayer1->submarine->getOrientation());
				boardPlayer1.placeShip("Destroyer", num2Char[fleetPlayer1->destroyer->getX()], fleetPlayer1->destroyer->getY(), fleetPlayer1->destroyer->getOrientation());

				if (fleetPlayer2->carrier->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Carrier", num2Char[fleetPlayer2->carrier->getX()], fleetPlayer2->carrier->getY(), fleetPlayer2->carrier->getOrientation());
				}
				if (fleetPlayer2->battleship->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Battleship", num2Char[fleetPlayer2->battleship->getX()], fleetPlayer2->battleship->getY(), fleetPlayer2->battleship->getOrientation());
				}
				if (fleetPlayer2->cruiser->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Cruiser", num2Char[fleetPlayer2->cruiser->getX()], fleetPlayer2->cruiser->getY(), fleetPlayer2->cruiser->getOrientation());
				}
				if (fleetPlayer2->submarine->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Submarine", num2Char[fleetPlayer2->submarine->getX()], fleetPlayer2->submarine->getY(), fleetPlayer2->submarine->getOrientation());
				}
				if (fleetPlayer2->destroyer->getSunk() == SUNK)
				{
					boardViewPlayer1.placeShip("Destroyer", num2Char[fleetPlayer2->destroyer->getX()], fleetPlayer2->destroyer->getY(), fleetPlayer2->destroyer->getOrientation());
				}

				for (int i = 0; i < logPlayer1->x.size(); i++)
				{
					boardViewPlayer1.placeBomb(num2Char[logPlayer1->x[i]], logPlayer1->y[i]);
				}
				for (int i = 0; i < logPlayer2->x.size(); i++)
				{
					boardPlayer1.placeBomb(num2Char[logPlayer2->x[i]], logPlayer2->y[i]);
				}
				gameWindow.display();


				//printf("\nPress any key to continue");
				//scanf(" %c", &dummyChar);
				//system("cls");

			} while (b1.status[0] == NSUNK && b1.status[1] == NSUNK);

			if (b1.getStatusPlayer1() == SUNK)
			{
				printf("CPU Has Won!\n");
				gameWindow.close();
				//gameWindow2.close();
			}
			else
			{
				printf("Player has won!\n");
				gameWindow.close();
			}

		}

	}


	//hello

private:
	board b1;

	friend class board;



	logBook* logPlayer1;
	logBook* logPlayer2;

	fleet* fleetPlayer1;
	fleet* fleetPlayer2;

	char num2Char[10] = { 'A','B','C','D','E','F','G','H','I','J' };
	//					   0   1   2   3   4   5   6   7   8   9
};