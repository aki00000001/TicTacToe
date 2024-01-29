#include "AutoPlayer.h"

AutoPlayer::AutoPlayer(char* playerName, bool autoModeEn) : Player(playerName, autoModeEn)
{}

Move AutoPlayer::GetNextMove(Board* ticTacBoard)
{
	Display::PromptPlayersTurn(name);

	Move bestMove = MinMaxController::SelectBestMove(ticTacBoard, symbol);

	return bestMove;
}
