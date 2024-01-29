#include <vector>
#include "MinMaxController.h"

using std::vector;

typedef void (*SelectMinMaxScore)(int&, int&);
typedef void (*SelectMinMaxMove)(int&, int&, Move&, Move&);

// In future move this functions to private section of class MinMaxController.
void SelectMaxScore(int& currentScore, int& bestScore);
void SelectMinScore(int& currentScore, int& bestScore);
void SelectMaxMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove);
void SelectMinMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove);

Move MinMaxController::SelectBestMove(Board* ticTacBoard, XO symbol)
{
	vector<Move> availableMoves = ticTacBoard->GetAvailableMoves();
	Move bestMove{ *(availableMoves.begin()) };
	int bestScore = symbol == X ? -100 : 100;
	SelectMinMaxMove SelectMove = symbol == X ? SelectMaxMove : SelectMinMove;

	for (int iMove = 0; iMove < ticTacBoard->nAvailableMoves; iMove++)
	{
		int currentScore;

		Move currentMove = *(availableMoves.begin() + iMove);

		ticTacBoard->SetMove(currentMove, symbol);

		TerminalState score = ticTacBoard->DetermineGameState();

		if (score == InProgress)
		{
			//availableMoves.erase(availableMoves.begin() + iMove);
			XO nextSymbol = symbol == X ? O : X;
			currentScore = MinMax(ticTacBoard, nextSymbol);
			//availableMoves.insert(availableMoves.begin() + iMove, currentMove);
		}
		else
		{
			currentScore = (int)score;
		}
		ticTacBoard->RevertMove(currentMove);
		SelectMove(currentScore, bestScore, currentMove, bestMove);
	}
	return bestMove;
}

int MinMaxController::MinMax(Board* ticTacBoard, XO symbol)
{
	vector<Move> availableMoves = ticTacBoard->GetAvailableMoves();
	int bestScore = symbol == X ? -100 : 100;
	SelectMinMaxScore selectScore = symbol == X ? SelectMaxScore : SelectMinScore;

	for (int iMove = 0; iMove < ticTacBoard->nAvailableMoves; iMove++)
	{
		int currentScore{};

		Move move = *(availableMoves.begin() + iMove);
		
		ticTacBoard->SetMove(move, symbol);

		TerminalState score = ticTacBoard->DetermineGameState();

		if (score == InProgress)
		{
			//availableMoves.erase(availableMoves.begin() + iMove);
			XO nextSymbol = symbol == X ? O : X;
			currentScore = MinMax(ticTacBoard, nextSymbol);
			selectScore(currentScore, bestScore);
			//availableMoves.insert(availableMoves.begin() + iMove, move);
		}
		else
		{
			bestScore = (int)score;
		}

		ticTacBoard->RevertMove(move);
	}
	return bestScore;
}

void SelectMaxScore(int& currentScore, int& bestScore)
{
	if (currentScore > bestScore)
	{
		bestScore = currentScore;
	}
	else
	{
		// Do nothing.
	}
}

void SelectMinScore(int& currentScore, int& bestScore)
{
	if (currentScore < bestScore)
	{
		bestScore = currentScore;
	}
	else
	{
		// Do nothing.
	}
}

void SelectMaxMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove)
{
	if (currentScore > bestScore)
	{
		bestScore = currentScore;
		bestMove = currentMove;
	}
	else
	{
		// Do nothing.
	}
}

void SelectMinMove(int& currentScore, int& bestScore, Move& currentMove, Move& bestMove)
{
	if (currentScore < bestScore)
	{
		bestScore = currentScore;
		bestMove = currentMove;
	}
	else
	{
		// Do nothing.
	}
}
