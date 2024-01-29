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

	while ((int)availableMoves.size() > 0)
	{
		int currentScore;
		int iMove = (int)availableMoves.size() > 1 ? rand() % (int)availableMoves.size() : 0;
		Move currentMove = *(availableMoves.begin() + iMove);
		availableMoves.erase(availableMoves.begin() + iMove);
		ticTacBoard->SetMove(currentMove, symbol);

		TerminalState score = ticTacBoard->DetermineGameState();

		if (score == InProgress)
		{
			XO nextSymbol = symbol == X ? O : X;
			currentScore = MinMax(ticTacBoard, nextSymbol);
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

	while ((int)availableMoves.size() > 0)
	{
		int currentScore;
		int iMove = (int)availableMoves.size() > 1 ? rand() % (int)availableMoves.size() : 0;
		Move move = *(availableMoves.begin() + iMove);
		availableMoves.erase(availableMoves.begin() + iMove);

		ticTacBoard->SetMove(move, symbol);

		TerminalState score = ticTacBoard->DetermineGameState();

		if (score == InProgress)
		{
			XO nextSymbol = symbol == X ? O : X;
			currentScore = MinMax(ticTacBoard, nextSymbol);
			selectScore(currentScore, bestScore);
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
