#pragma once
#include "Player.h"
#include "MinMaxController.h"

class AutoPlayer : public Player
{
private:
	MinMaxController* controller;

public:
	AutoPlayer(char* playerName, XO sym, MinMaxController* controller);

	void GetNextMove(Move& outMove);

	virtual ~AutoPlayer();
};
