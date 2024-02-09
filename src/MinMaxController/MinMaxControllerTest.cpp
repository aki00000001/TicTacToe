#include "gtest/gtest.h"
#include "Board.h"
#include "Move.h"
#include "MinMaxController.h"

struct MinMaxControllerFixture : public testing::Test
{
	MinMaxController* controller;
	Board* board;
	std::vector<Move> moves;

	void SetUp() 
	{ 
		board      = new Board();
		controller = new MinMaxController(board);
		moves.reserve(9);
		moves.emplace_back(1, 1);
		moves.emplace_back(1, 2);
		moves.emplace_back(1, 3);
		moves.emplace_back(2, 1);
		moves.emplace_back(2, 2);
		moves.emplace_back(2, 3);
		moves.emplace_back(3, 1);
		moves.emplace_back(3, 2);
		moves.emplace_back(3, 3);
	}

	void TearDown()
	{
		delete board;
		delete controller;
	}
};

namespace MinMaxControllerTests
{
	TEST_F(MinMaxControllerFixture, SelectBestMoveForOTest)
	{
		board->SetMove(moves[0], X);
		board->SetMove(moves[2], X);
		board->SetMove(moves[3], O);

		Move actualBestMove;
		controller->SelectBestMove(O, actualBestMove);
		EXPECT_EQ(moves[1], actualBestMove);
	}

	TEST_F(MinMaxControllerFixture, SelectBestMoveForXTest)
	{
		board->SetMove(moves[3], O);
		board->SetMove(moves[4], O);
		board->SetMove(moves[0], X);

		Move actualBestMove;
		controller->SelectBestMove(O, actualBestMove);
		EXPECT_EQ(moves[5], actualBestMove);
	}

	TEST_F(MinMaxControllerFixture, SelectBestMoveForXWinTest)
	{
		board->SetMove(moves[0], X);
		board->SetMove(moves[1], X);
		board->SetMove(moves[6], O);
		board->SetMove(moves[7], O);

		Move actualBestMove;
		controller->SelectBestMove(X, actualBestMove);
		EXPECT_EQ(moves[2], actualBestMove);
	}

	TEST_F(MinMaxControllerFixture, SelectBestMoveForOWinTest)
	{
		board->SetMove(moves[0], O);
		board->SetMove(moves[3], O);
		board->SetMove(moves[1], X);
		board->SetMove(moves[4], X);

		Move actualBestMove;
		controller->SelectBestMove(O, actualBestMove);
		EXPECT_EQ(moves[6], actualBestMove);
	}
}