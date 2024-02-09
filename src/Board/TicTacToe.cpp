#include <windows.h>
#include <time.h>
#include "TicTacToe.h"
#include "AutoPlayer.h"

TicTacToe::TicTacToe()
	:board(Board()), gameState(InProgress), controller(MinMaxController(&board))
{
	XO sym = GetRandomSymbol();
	for (int i = 0; i < 2; i++)
	{
		char playerName[10];
		bool autoModeEn = false;
		Display::PromptPlayerForDetails(playerName, autoModeEn);
		sym = sym == X ? O : X;
		if (autoModeEn)
		{
			players[i] = new AutoPlayer(playerName, sym, &controller);
		}
		else
		{
			players[i] = new Player(playerName, sym);
		}
	}
	currentPlayer = players[0]->GetSymbol() == X ? players[1] : players[0];
}

void TicTacToe::ExecuteGameEvent()
{
	while (gameState == InProgress)
	{
		currentPlayer = currentPlayer == players[0] ? players[1] : players[0];
		board.DisplayBoard();
		RunGameCycle();
	}

	board.DisplayBoard();

	gameState == Draw ? board.PromptDraw() : currentPlayer->DeclareWinner();

	for (int i = 1; i >= 0; i--)
	{
		delete players[i];
		players[i] = NULL;
	}
}

void TicTacToe::RunGameCycle()
{
	bool moveValidity = false;
	Move move{};
	while (!moveValidity)
	{
		currentPlayer->GetNextMove(move);
		moveValidity = board.SetMove(move, currentPlayer->GetSymbol());
	}
	gameState = board.DetermineGameState();
	Sleep(250);
}

XO TicTacToe::GetRandomSymbol()
{
	srand((unsigned int)time(0));
	int randomNo = rand() % 2;
	return randomNo > 0 ? X : O;
}
