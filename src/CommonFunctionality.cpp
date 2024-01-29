//#include <string>
//#include "CommonFunctionality.h"
//#include "Display.h"
//
//using std::string;
//using std::vector;
//
//
//bool CheckMoveAvailability(vector<Move> availableMoves, Move move)
//{
//	bool moveAvaialble = false;
//	for (vector<Move>::iterator itr = availableMoves.begin(); itr != availableMoves.end(); itr++)
//	{
//		if (itr->row == move.row && itr->col == move.col) 
//		{
//			moveAvaialble = true;
//		}
//	}
//
//	return moveAvaialble;
//}
//
//void SetInitialStateOfPlayer(Player*& ptr, Player* players)
//{
//	if (players->GetSymbol() != XO::X)
//	{
//		ptr = players + 1;
//	}
//	else
//	{
//		// Do nothing.
//	}
//}
//
//void SetPlayerForNextTurn(TerminalState gameState, Player* &ptr, Player* players)
//{
//	if (gameState == InProgress)
//	{
//		if (ptr->GetSymbol() == players->GetSymbol())
//		{
//			ptr = players + 1;
//		}
//		else
//		{
//			ptr = players;
//		}
//	}
//}
//
//void DeterminePlayerSymbol(Player* players)
//{
//	srand((unsigned int)time(NULL));
//	int randomNo = rand() % 2;
//	XO playerSymbol = randomNo > 0 ? XO::X : XO::O;
//	players->SetSymbol(playerSymbol);
//
//	players++;
//	playerSymbol = playerSymbol == XO::X ? XO::O : XO::X;
//	players->SetSymbol(playerSymbol);
//}