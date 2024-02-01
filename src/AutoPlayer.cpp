#include "AutoPlayer.h"
#include <time.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

AutoPlayer::AutoPlayer(char* playerName, bool autoModeEn) : Player(playerName, autoModeEn)
{}

Move AutoPlayer::GetNextMove(Board* ticTacBoard)
{
	clock_t start, end;
	PromptPlayersTurn(name);
	start = clock();
	Move bestMove = SelectBestMove(ticTacBoard, symbol);
	end = clock();

	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by program is : " << std::fixed
		<< time_taken << "sec" << endl;// setprecision(5);

	return bestMove;
}
