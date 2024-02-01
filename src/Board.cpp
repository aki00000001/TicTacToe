# include "Board.h"
# include <string>
#include <iostream>

using std::string;
using std::vector;

Board::Board()
	:brd{ _, _, _ , _ , _ , _ , _ , _ , _ }, nAvailableMoves(9)
{}

bool Board::SetMove(Move& move, XO symbol)
{
	bool moveValidity = false;
	moveValidity = CheckIfMoveValid(move);
	
	if (moveValidity)
	{
		brd[move.ArrayIndex()] = symbol;
		nAvailableMoves--;
	}
	else
	{
		// Do nothing.
	}
	return moveValidity;
}

void Board::RevertMove(Move& move)
{
	brd[move.ArrayIndex()] = _;
	nAvailableMoves++;
}

void Board::GetAvailableMoves(vector<Move>& availableMove)
{
	for (unsigned int i = 1; i < 4; i++)
	{
		for (unsigned int j = 1; j < 4; j++)
		{
			int idx = ArrayIdx(i, j);
			if (brd[idx] == _)
			{
				availableMove.emplace_back(i, j);
			}
			else
			{
				// Do nothing.
			}
		}
	}
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
	if (!move.InRange())
	{
		string message = "Error: Row and column should be between 1 and 3.\nEntered move is (row, col):";
		message = move + message;
		message = message + "\nEnter new move.";
		PromptError(message);
	}
	else if (!CheckMoveAvailability(move))
	{
		string message = "Error: Enter Rows and columns is occupied.\nEntered move is (row, col):";
		message = move + message;
		message = message + "\nEnter new move.";
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
	if (brd[move.ArrayIndex()] == _)
	{
		moveAvailable = true;
	}
	else
	{
		// Do nothing.
	}
	return moveAvailable;
}
