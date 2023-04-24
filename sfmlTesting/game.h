#include "header.h"

class ship
{
public:
	ship(int uPlayer, int uHP, char uIdentification, int uHit, int uSunk)
	{
		player = uPlayer;
		hp = uHP;
		identification = uIdentification;
		hit = uHit;
		sunk = uSunk;
	}

	void setShip(int uHP, char uIdentification, int uHit, int uSunk)
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


private:
	int player;
	int hp;
	char identification;
	int hit;
	int sunk;

	int x;
	int y;
	int orintation;
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
		if (whoPlay == PLAYER1)
		{
			if (yesNo(1) == 0)
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
	}

	int getStatusPlayer1()
	{
		return status[0];
	}
	int getStatusPlayer2()
	{
		return status[1];
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

	int status[2] = { 0,0 };

	int infoX;
	int infoY;
	int infoRotation;

protected:
	int yesNo(int type)
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

	}


	void placeMan(char board[][10], int size, char identification, class fleet& ref)
	{
		int x = 0, y = 0;
		int placeable = YES;
		int rotation[4] = { 0 };
		// left, right, down, up

		int choice = 0;

		// scanf("%d %d", &x, &y); 
		inputCheck(1, board, &x, &y, rotation, &choice); // x and y input



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
		}
		if (rotation[1] == 1)
		{
			printf("2) You can rotate right\n");
		}
		if (rotation[2] == 1)
		{
			printf("3) You can rotate down\n");
		}
		if (rotation[3] == 1)
		{
			printf("4) You can roate up\n");
		}
		// what if no roations were found? Put in check code

		printf("What would you like to do? Pick the corresponding number: ");
		//scanf("%d", &choice);
		inputCheck(2, board, &x, &y, rotation, &choice); // rotation choice input

		int uRot;

		switch (choice)
		{
		case 1: // rotate left
			uRot = 270;
			for (int i = x; i >= x - size; i--)
			{
				board[y][i] = identification;
			}
			break;

		case 2: // rotate rigght
			uRot = 90;
			for (int i = x; i <= x + size; i++)
			{
				board[y][i] = identification;
			}
			break;

		case 3: // rotate down
			uRot = 180;
			for (int i = y; i <= y + size; i++)
			{
				board[i][x] = identification;
			}
			break;

		case 4: // roate up
			uRot = 0;
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
			ref.cruiser->setOrientation(uRot);
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

	void inputCheck(int checkType, char board[][10], int* x, int* y, int rotation[], int* choice)
	{
		int tryAgain = YES;

		if (checkType == 1)
		{
			scanf("%d %d", x, y);

			while (tryAgain == YES)
			{
				if (board[*y][*x] != '~')
				{
					printf("\nYou picked a coordinate that has already been taken by other ship\n Select a different coordinate: ");
					scanf("%d %d", x, y);

				}
				else
				{

					while (tryAgain == YES)
					{
						if (*x > 9 && *x < 0)
						{
							printf("\nYour X is out of bounds, enter within the bound (0 <= x <= 9): ");
							scanf("%d", x);
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
							printf("\nYour Y is out of bounds, enter within the bound (0 <= x <= 9): ");
							scanf("%d", y);
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
			while (tryAgain == YES)
			{

				if (rotation[*choice - 1] != 1)
				{
					printf("\n You selected an invalid number, selec a valid rotation: ");
					scanf("%d", choice);
				}
				else
				{
					tryAgain = NO;
				}
			}

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

		autoCheck(2, board, &x, &y, rotation, &choice); // rotation choice input
		int uRot;

		switch (choice)
		{
		case 1: // rotate left
			uRot = 270;
			for (int i = x; i >= x - size; i--)
			{
				board[y][i] = identification;
			}
			break;

		case 2: // rotate rigght
			uRot = 90;
			for (int i = x; i <= x + size; i++)
			{
				board[y][i] = identification;
			}
			break;

		case 3: // rotate down
			uRot = 180;
			for (int i = y; i <= y + size; i++)
			{
				board[i][x] = identification;
			}
			break;

		case 4: // roate up
			uRot = 0;
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
			ref.cruiser->setOrientation(uRot);
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



	void runGame()
	{
		sf::RenderWindow window(sf::VideoMode(880 * 2, 880), "Game Board!");
		//sf::Style::Resize
		Board boardPlayer1(window);
		Board boardViewPlayer1(window);



		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();




			}


			window.clear();
			boardPlayer1.drawBoard(0, 0);
			boardViewPlayer1.drawBoard(11, 0);



			boardViewPlayer1.placeShip("Cruiser", 'A', 6, 0);
			boardViewPlayer1.placeBomb('A', 1);
			boardPlayer1.placeShip("Destroyer", 'B', 5, 0);
			boardViewPlayer1.placeBomb('B', 6);
			//  board.placeShip("Cruiser", 'E', 0, 90);
			//  window.draw(text);
			window.display();











			//b1.printBoard(PLAYER1);
			char dummyChar = '\0';


			b1.printBoard(BOARDPLAYER1);
			b1.placeShip(PLAYER1);




			// Placing ships on computer's board
			b1.placeShip(PLAYER2);
			printf("Computer Board\n"); // debug code, speeds up testing of game
			b1.printBoard(BOARDPLAYER2);
			do
			{

				printf("	   Enemy Area\n");
				b1.printBoard(BOARDVIEWPLAYER2);
				printf("	You Area of Operations\n");
				b1.printBoard(BOARDPLAYER1);
				b1.fire(PLAYER1);
				printf("\nPress any key to continue");
				scanf(" %c", &dummyChar);
				system("cls");

				b1.fire(PLAYER2);
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

};