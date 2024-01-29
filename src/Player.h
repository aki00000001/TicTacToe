#pragma once

#include "Board.h"
#include "CommonDatatypes.h"

class Player : public  Display
{
protected:
	char name[10];
	bool autoModeEnable;
	XO symbol;

public:
	Player(char* playerName, bool autoModeEn);

	void SetSymbol(XO symbol);

	XO GetSymbol();

	virtual Move GetNextMove(Board* ticTacBoard);

	void DeclareWinner();

	~Player();
private:
	const char* GetName();
};