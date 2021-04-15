// Jason Hurley | 10.27.19 | Final Project Dr. Dulaney
/*
This is a game of Tic-Tac-Toe in C++. The guidelines for this assignment are as follows.

• Two players will play the game, player 1 and player 2
	o Player 1 will place an X by choosing the row and column number
	o Player 2 will place an O by choosing the row and column number
	o If a player tries to place a symbol on a spot that already has been taken, an error will be displayed and the player will be asked to place the symbol at a valid location
	o If a player tries to place a symbol on a spot outside the grid, an error will be displayed and the player will be asked to place the symbol at a valid location

• Required functions
	o A function should be utilized to display the grid called displayGrid
	o A function should be utilized when a choice is made.  This should be called makeChoice
	o A function should be utilized when checking to see if a player has won.  This should be called checkWin

	o Be prepared to utilize a 2-dimensional arrays
	o Arrays passed into functions are always passed by reference
	o Draw out the grid to figure out your logic to see if a player has won
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Global Variable
const int COL = 3;

// Function Prototypes
void displayGrid(char[][COL], int);		// Displays Playing Grid
void makeChoice(char[][COL], int);		// Make Choice Loop; Runs the Game
int checkWin(char[][COL], int, bool);	// Checks the Array for Win or Draw

int main()
{
	// Step 1; Prompt User
	cout << "Welcome to Tic-Tac-Toe!\n\n";
	cout << "~ Rules ~\n\n";
	cout << "Player 1: X\n";
	cout << "Player 2: O\n";
	cout << "Each player will get one turn to make a move! You will follow the traditional rules of Tic-Tac-Toe!\n";
	cout << "Make sure to only place your selection in a valid row/column! Enjoy :^)\n\n";

	// Step 2; Define Variables
	const int ROW = 3;
	char grid[ROW][COL] = { {'-', '-', '-',},
							{'-', '-', '-',},
							{'-', '-', '-',} };

	// Step 3; Call Display Grid Function; Displays Initial Grid
	displayGrid(grid, ROW);

	// Step 4; Make Choice Loop; Runs Game and Calls Appropriate Functions
	makeChoice(grid, ROW);
	
	// Step 5; End Program
	system("PAUSE");
	return 0;
}

// Display Grid Function
/*
The DisplayGrid function displays a grid of 3x3 (Tic-Tac-Toe Board) using a constant variable passed into the function (COL) as well
as the ROW integer. This displays the grid each turn that is taken and is referenced both in the MAIN function and the MAKECHOICE
function.
*/
void displayGrid(char grid[][COL], int row)
{
	cout << "\n" << setw(11) << "COL" << setw(5) << "COL" << setw(6) << "COL\n";
	cout << setw(10) << "1" << setw(5) << "2" << setw(5) << "3" << endl << endl;
	for (int i = 0; i < row; i++)
	{
		cout << "ROW " << i + 1;

		for (int j = 0; j < COL; j++)
		{
			cout << setw(5) << grid[i][j];
		}

		cout << endl << endl;
	}
}

// Make Choice Function
/*
The make choice function is the primary program function in the Tic Tac Toe Program. This function accomplishes multiple steps
as well as calling other functions. Steps include:

1. Get Player 1 Choice
	- Validate that choice is within bounds (ROW and COL)
	- Validate that space chosen is not taken, if so, requests a new ROW and COL
2. GRID is accessed via rowChoice Variable and colChoice (grid[rowChoice][colChoice]
3. The character literal 'X' is put into the specified area of the 2-D array.
4. The CHECKWIN function is called, checking for a win, draw, or move to next player.
	- If 1 is returned, a win is TRUE, loop stops, and player one wins.
		- Value (1) is also returned in a DRAW.
	- If 0 is returned, a win is FALSE, loop continues, and player 2 makes move.
5. Display Grid is called to prepare for Player 2.
6. Process repeats for Player 2.
*/

void makeChoice(char grid[][COL], int ROW)
{
	// Variable Declaration
	bool i = 0;

	// Loop; Primary Loop that Runs the Game
	while (i == 0)
	{
		// Variable Declaration
		int rowChoice = 0;
		int colChoice = 0;

// ****************************************** PLAYER 1 ******************************************
		cout << "\nPlayer 1's Turn\n";
		cout << "Please choose a Row (1-3)\n";
		cin >> rowChoice;
		rowChoice--;

		while (rowChoice < 0 || rowChoice > 2)														// Checks Placement Validity
		{
			cout << "\nERROR! Please enter a Valid Row Choice: ";
			cin >> rowChoice;
			rowChoice--;
		}
		
		cout << "Please choose a Column (1-3)\n";
		cin >> colChoice;
		colChoice--;

		while (colChoice < 0 || colChoice > 2)
		{
			cout << "\nERROR! Please enter a Valid Column Choice: ";									// Checks Placement Validity
			cin >> colChoice;
			colChoice--;
		}

		while (grid[rowChoice][colChoice] == 'X' || grid[rowChoice][colChoice] == 'O')				// Checks Spot Occupation
		{
			cout << "ERROR! You have selected an occupied spot. Please select a new Row and Column!\n";

			cout << "\nPlayer 1's Turn\n";
			cout << "Please choose a Row (1-3)\n";
			cin >> rowChoice;
			rowChoice--;

			while (rowChoice < 0 || rowChoice > 2)													// Checks Placement Validity
			{
				cout << "ERROR! Please enter a Valid Row Choice: ";
				cin >> rowChoice;
				rowChoice--;
			}

			cout << "Please choose a Column (1-3)\n";
			cin >> colChoice;
			colChoice--;

			while (colChoice < 0 || colChoice > 2)													// Checks Placement Validity
			{
				cout << "ERROR! Please enter a Valid Column Choice: ";
				cin >> colChoice;
				colChoice--;
			}
		}

		grid[rowChoice][colChoice] = 'X';
		i = checkWin(grid, ROW, i);
		displayGrid(grid, ROW);

		if (i == 1)
			return;

// **********************************************************************************************


		// Reset Choice...
		rowChoice = 0;
		colChoice = 0;


// Player 2
// ****************************************** PLAYER 2 ******************************************
		cout << "\nPlayer 2's Turn\n";
		cout << "Please choose a Row (1-3)\n";
		cin >> rowChoice;
		rowChoice--;

		while (rowChoice < 0 || rowChoice > 2)
		{
			cout << "ERROR! Please enter a Valid Row Choice: ";											// Checks Placement Validity
			cin >> rowChoice;
			rowChoice--;
		}

		cout << "Please choose a Column (1-3)\n";
		cin >> colChoice;
		colChoice--;

		while (colChoice < 0 || colChoice > 2)															// Checks Placement Validity
		{
			cout << "ERROR! Please enter a Valid Column Choice: ";
			cin >> colChoice;
			colChoice--;
		}

		while (grid[rowChoice][colChoice] == 'X' || grid[rowChoice][colChoice] == 'O')					// Checks for Occupied Spot
		{
			cout << "ERROR! You have selected an occupied spot. Please select a new Row and Column!\n";

			cout << "\nPlayer 2's Turn\n";
			cout << "Please choose a Row (1-3)\n";
			cin >> rowChoice;
			rowChoice--;

			while (rowChoice < 0 || rowChoice > 2)														// Checks Placement Validity
			{
				cout << "ERROR! Please enter a Valid Row Choice: ";
				cin >> rowChoice;
				rowChoice--;
			}

			cout << "Please choose a Column (1-3)\n";
			cin >> colChoice;
			colChoice--;

			while (colChoice < 0 || colChoice > 2)														// Checks Placement Validity
			{
				cout << "ERROR! Please enter a Valid Column Choice: ";
				cin >> colChoice;
				colChoice--;
			}
		}

		grid[rowChoice][colChoice] = 'O';
		i = checkWin(grid, ROW, i);
		displayGrid(grid, ROW);

		if (i == 1)
			return;

// *************************************************************************************************
	}
}

// CHECK WIN FUNCTION
/*
The CHECKWIN function checks to see if any of the criteria for a win are present. The way the function works is to analyze the different ways of winning
a game of classic Tic-Tac-Toe (Across, Down, Diagonal). If the criteria for a win is met, the function congratulates the appropriate user then increases
the variable I by one, breaking the game loop in the MAKECHOICE function. This allows the players to play until a draw or a win statement is satisfied. If
neither are satisfied, the ELSE statement simply returns ZERO, allowing the MAKECHOICE function to loop until a win or draw is satisfied.
*/
int checkWin(char grid[][COL], int ROW, bool i)
{
	// Player Win Check
	if ((grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X') || (grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O'))
	{
		if (grid[0][0] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X') || (grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O'))
	{
		if (grid[1][0] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X') || (grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O'))
	{
		if (grid[2][0] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X') || (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O'))
	{
		if (grid[0][0] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X') || (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O'))
	{
		if (grid[0][1] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X') || (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O'))
	{
		if (grid[0][2] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') || (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O'))
	{
		if (grid[0][0] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X') || (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O'))
	{
		if (grid[0][2] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[2][2] == 'X' && grid[1][1] == 'X' && grid[0][0] == 'X') || (grid[2][2] == 'O' && grid[1][1] == 'O' && grid[0][0] == 'O'))
	{
		if (grid[2][2] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[2][0] == 'X' && grid[1][1] == 'X' && grid[0][2] == 'X') || (grid[2][0] == 'O' && grid[1][1] == 'O' && grid[0][2] == 'O'))
	{
		if (grid[2][0] == 'X')
		{
			cout << "\nPlayer 1 has won!";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
		else
		{
			cout << "\nPlayer 2 has won!\n\n";
			cout << " Final Grid is:\n\n";
			i++;
			return i;
		}
	}

	else if ((grid[0][0] != '-' && grid[0][1] != '-' && grid[0][2] != '-' && grid[1][0] != '-' && grid[1][1] != '-' && grid[1][2] != '-' && grid[2][0] != '-' && grid[2][1] != '-' && grid[2][2] != '-'))
	{
		cout << "\nGame is a Draw!!!";
		cout << " Final Grid is:\n\n";
		i++;
		return i;
	}

	else
	{
		return i;
	}
}