#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "TicTacToe.h"
#include "AutoPlayer.h"

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 2; i++)
	{
		char playerName[10];
		bool autoModeEn = false;
		Display::PromptPlayerForDetails(playerName, autoModeEn);
		if (autoModeEn)
		{
			players[i] = new AutoPlayer(playerName, autoModeEn);
		}
		else
		{
			players[i] = new Player(playerName, autoModeEn);
		}
	}

	DeterminePlayerSymbol();
}

void TicTacToe::ExecuteGameEvent()
{
	while (gameState == InProgress)
	{
		SetCurrentPlayerForTurn();
		board.DisplayBoard();
		RunGameCycle();
	}

	board.DisplayBoard();

	gameState == Draw ? board.PromptDraw() : currentPlayer->DeclareWinner();
	delete players[0];
	delete players[1];
}

void TicTacToe::RunGameCycle()
{
	bool moveValidity = false;
	Move move{};
	while (!moveValidity)
	{
		move         = currentPlayer->GetNextMove(&board);
		moveValidity = board.SetMove(move, currentPlayer->GetSymbol());
	}
	gameState = board.DetermineGameState();
	Sleep(250);
}

void TicTacToe::DeterminePlayerSymbol()
{
	srand((unsigned int)time(NULL));
	int randomNo = rand() % 2;

	if (randomNo > 0)
	{
		players[0]->SetSymbol(X);
		players[1]->SetSymbol(O);
		currentPlayer = players[1];
	}
	else
	{
		players[0]->SetSymbol(O);
		players[1]->SetSymbol(X);
		currentPlayer = players[0];
	}
}

void TicTacToe::SetCurrentPlayerForTurn()
{
	currentPlayer = currentPlayer == players[0] ? players[1] : players[0];
}
