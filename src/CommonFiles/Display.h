#pragma once
#include <string>
#include <vector>
#include "CommonDatatypes.h"
#include "Move.h"

class Display {
public:
	void DisplayBoard(XO* brd);

	void PromptPlayersTurn(const char* playerName);

	void PromptPlayerForMove(const char* playerName, Move& move);

	void PromptDraw();

	void PromptWinner(const char* turn);

	void PromptError(const std::string& message);

	static void PromptPlayerForDetails(char* playerName, bool& autoMode);
};