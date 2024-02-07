#include "gtest/gtest.h"
#include "Move.h"
#include <iostream>

namespace
{
	TEST(MoveTests, ConstructorTest)
	{
		Move m1;
		Move m2(1, 1);
		EXPECT_NE(m1, m2);

		Move m3(0, 0);
		EXPECT_EQ(m1, m3);
		
		m1 = m2;
		EXPECT_EQ(m1, m2);
	}

	TEST(MoveTests, InRangeTest)
	{
		Move m1;
		EXPECT_FALSE(m1.InRange());

		Move m2(4, 4);
		EXPECT_FALSE(m2.InRange());

		Move m3(3, 4);
		EXPECT_FALSE(m3.InRange());

		Move m4(4, 3);
		EXPECT_FALSE(m4.InRange());

		Move m5(1, 1);
		EXPECT_TRUE(m5.InRange());

		Move m6(3, 3);
		EXPECT_TRUE(m6.InRange());
	}

	TEST(MoveTests, ArrayIndexTest)
	{
		Move m1;
		EXPECT_EQ(-4, m1.ArrayIndex());

		Move m2(2, 2);
		EXPECT_EQ(4, m2.ArrayIndex());
	}

	TEST(MoveTests, OperatorTest)
	{
		Move m1;
		Move m2;
		EXPECT_TRUE(m1 == m2);
		EXPECT_FALSE(m1 != m2);
		
		std::string expectedString = "This is move: (0, 0)";
		std::string actualString   = "This is move: ";
		actualString               = m1 + actualString;
		EXPECT_EQ(actualString, expectedString);
	}
}