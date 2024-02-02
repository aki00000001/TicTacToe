#include "Display.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Display::DisplayBoard(XO* brd)
{
	system("cls");
	
	char symbol[9];
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			symbol[ArrayIdx(i, j)] = brd[ArrayIdx(i, j)] != _ ? brd[ArrayIdx(i, j)] == O ? 'O' : 'X' : ' ';
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

void Display::PromptPlayerForMove(const char* playerName, Move& move)
{
	PromptPlayersTurn(playerName);
	cin >> move;
}

void Display::PromptWinner(const char* turn)
{
	cout << "The winner is " << turn << endl;
}

void Display::PromptDraw()
{
	cout << "It's a draw " << endl;
}

void Display::PromptError(const std::string& errorMessage)
{
	cout << errorMessage << endl;
}

void Display::PromptPlayerForDetails(char* playerName, bool& autoMode) {
	cout << "Enter Player name: ";
	cin >> playerName;
	bool validPlayerType = false;
	do
	{
		cout << "Enter Player type (manual = m / CPU = c): ";
		char playerType;
		cin >> playerType;
		validPlayerType = playerType == 'm' || playerType == 'c' ? true : false;
		autoMode = playerType == 'm' ? false : true;
	} while (!validPlayerType);
	system("cls");
}