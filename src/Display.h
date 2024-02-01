#pragma once
#include <string>
#include "CommonDatatypes.h"
#include "Move.h"
#include <vector>

class Display {
public:
	void DisplayBoard(XO* brd);

	void PromptPlayersTurn(const char* playerName);

	Move PromptPlayerForMove(const char* playerName);

	void PromptDraw();

	void PrompWinner(const char* turn);

	void PromptError(const std::string& message);

	static void PromptPlayerForDetails(char* playerName, bool& autoMode);
};