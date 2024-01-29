# include "Board.h"
# include <string>

using std::string;
using std::vector;

Board::Board()
	:brd{ _, _, _, _, _, _, _, _, _ }, nAvailableMoves(9)
{}

bool Board::SetMove(Move& move, XO symbol)
{
	bool moveValidity = false;
	moveValidity = CheckIfMoveValid(move);
	brd[(3 * move.row) + move.col] = symbol;
	if (moveValidity)
	{
		nAvailableMoves--;
	}
	else
	{
		// Do nothing.
	}
	return moveValidity;
}

void Board::RevertMove(Move& loc)
{
	brd[(3 * loc.row) + loc.col] = _;
	nAvailableMoves++;
}

vector<Move> Board::GetAvailableMoves()
{
	std::vector<Move> availableMove;
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			Move move{ i, j };
			if (brd[(3 * i) + j] == _)
			{
				availableMove.push_back(move);
			}
			else
			{
				// Do nothing.
			}
		}
	}
	return availableMove;
}

void Board::DisplayBoard()
{
	Display::DisplayBoard(brd);
}

TerminalState Board::DetermineGameState()
{
	TerminalState gameState;
	XO state = _;

	for (int i = 0; i < 3 && state == _; i++)
	{
		if ((brd[(3 * i) + 0] == brd[(3 * i) + 1]) && (brd[(3 * i) + 1] == brd[(3 * i) + 2]) && (brd[(3 * i) + 1] != _))
		{
			state = brd[(3 * i) + 1];
		}
	}

	for (int i = 0; i < 3 && state == _; i++)
	{
		if ((brd[0 + i] == brd[3 + i]) && (brd[3 + i] == brd[6 + i]) && (brd[3 + i] != _))
		{
			state = brd[3 + i];
		}
	}

	if ((brd[0] == brd[4]) && (brd[4] == brd[8]) && (brd[4] != _) && state == _)
	{
		state = brd[4];
	}

	if ((brd[2] == brd[4]) && (brd[4] == brd[6]) && (brd[4] != _) && state == _)
	{
		state = brd[4];
	}

	if (state == _ && nAvailableMoves == 0)
	{
		gameState = Draw;
	}
	else if (state == X)
	{
		gameState = X_Won;
	}
	else if (state == O)
	{
		gameState = O_Won;
	}
	else
	{
		gameState = InProgress;
	}

	return gameState;
}

bool Board::CheckIfMoveValid(Move& move)
{
	bool moveValidity = false;
	if (!(move.row < 3 && move.col < 3 && move.row >= 0 && move.col >= 0))
	{
		int row = move.row + 1;
		int col = move.col + 1;
		string message = "Error: Row and column should be between 1 and 3.\n";
		message = message + "Enter row is: " + std::to_string(row) + "\nEntered column is: " + std::to_string(col);
		message = message + "\nEnter correct row and column.";
		PromptError(message);
	}
	else if (!CheckMoveAvailability(move))
	{
		int row = move.row + 1;
		int col = move.col + 1;
		string message = "Error: Enter Rows and columns is occupied.\n";
		message = message + "Entered row is: " + std::to_string(row) + "\nEntered column is: " + std::to_string(col);
		message = message + "\nEnter empty row and column.";
		PromptError(message);
	}
	else
	{
		moveValidity = true;
	}

	return moveValidity;
}

bool Board::CheckMoveAvailability(Move &move)
{
	bool moveAvailable = false;
	if (brd[(3 * move.row) + move.col] == _)
	{
		moveAvailable = true;
	}
	else
	{
		// Do nothing.
	}
	return moveAvailable;
}
