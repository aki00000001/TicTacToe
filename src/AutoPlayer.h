#pragma once
#include "Player.h"
#include "MinMaxController.h"

class AutoPlayer : public Player, public MinMaxController
{
public:
	AutoPlayer(char* playerName, bool autoModeEn);

	Move GetNextMove(Board* ticTacBoard);
};
