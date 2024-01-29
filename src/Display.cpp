#include "Display.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Display::DisplayBoard(XO* brd)
{
	system("cls");
	
	char symbol[9];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			symbol[(3 * i) + j] = brd[(3 * i) + j] != _ ? brd[(3 * i) + j] == O ? 'O' : 'X' : ' ';
		}
	}

	cout << "         " << " Col 1 | Col 2 | Col 3 " << endl << endl;
	cout << "         " << "       |       |       " << endl;
	cout << "  Row 1: " << "   " << symbol[0] << "   |   " << symbol[1] << "   |   " << symbol[2] << "   " << endl;
	cout << "         " << "_______|_______|_______" << endl;
	cout << "         " << "       |       |       " << endl;
	cout << "  Row 2: " << "   " << symbol[3] << "   |   " << symbol[4] << "   |   " << symbol[5] << "   " << endl;
	cout << "         " << "_______|_______|_______" << endl;
	cout << "         " << "       |       |       " << endl;
	cout << "  Row 3: " << "   " << symbol[6] << "   |   " << symbol[7] << "   |   " << symbol[8] << "   " << endl;
	cout << "         " << "       |       |       " << endl;
}

void Display::PromptPlayersTurn(const char* playerName)
{
	cout << "It's " << playerName << "'s turn." << endl;
}

Move Display::PromptPlayerForMove(const char* playerName)
{
	PromptPlayersTurn(playerName);
	Move move{};
	int row, col;
	cout << "Enter row no. (between 1 and 3): ";
	cin >> move.row;
	move.row--;
	cout << "Enter column no. (between 1 and 3): ";
	cin >> move.col;
	move.col--;
	return move;
}

void Display::PrompWinner(const char* turn)
{
	cout << "The winner is " << turn << endl;
}

void Display::PromptDraw()
{
	cout << "It's a draw " << endl;
}

void Display::PromptError(std::string errorMessage)
{
	cout << errorMessage << endl;
}

void Display::PromptPlayerForDetails(char* playerName, bool& autoMode) {
	cout << "Enter Player name: ";
	cin >> playerName;

	cout << "Enter Player type (manual = m / auto = a): ";
	char playerType;
	cin >> playerType;
	autoMode = playerType == 'm' ? false : true;

	system("cls");
}