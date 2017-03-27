/**
 * Unit Tests for Piezas
 **/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, firstTurnShouldBeX)
{
	Piezas test;
	Piece starting = test.dropPiece(0);
	ASSERT_EQ(starting, X);
}

TEST(PiezasTest, secondTurnShouldBeO)
{
	Piezas test;
	Piece second = test.dropPiece(0);
	second = test.dropPiece(0);
	ASSERT_EQ(second, O);
}

TEST(PiezasTest, columnLessThan0)
{
	Piezas test;
	Piece starting = test.dropPiece(-1);
	ASSERT_EQ(starting, Invalid);
}

TEST(PiezasTest, columnTooBig)
{
	Piezas test;
	Piece starting = test.dropPiece(4);
	ASSERT_EQ(starting, Invalid);
}

TEST(PiezasTest, columnOverflow)
{
	Piezas test;
	Piece starting = test.dropPiece(2);
	starting = test.dropPiece(2);
	starting = test.dropPiece(2);
	starting = test.dropPiece(2);
	ASSERT_EQ(starting, Blank);
}

TEST(PiezasTest, pieceAtRowTooSmall)
{
	Piezas test;
	Piece bad = test.pieceAt(-1, 2);
	ASSERT_EQ(bad, Invalid);
}

TEST(PiezasTest, pieceAtColTooSmall)
{
	Piezas test;
	Piece bad = test.pieceAt(1, -2);
	ASSERT_EQ(bad, Invalid);
}

TEST(PiezasTest, pieceAtRowTooBig)
{
	Piezas test;
	Piece bad = test.pieceAt(3, 1);
	ASSERT_EQ(bad, Invalid);
}

TEST(PiezasTest, pieceAtColTooBig)
{
	Piezas test;
	Piece bad = test.pieceAt(1, 4);
	ASSERT_EQ(bad, Invalid);
}

TEST(PiezasTest, pieceAtBothBad)
{
	Piezas test;
	Piece bad = test.pieceAt(-1, 4);
	ASSERT_EQ(bad, Invalid);
}

TEST(PiezasTest, validPieceAtX)
{
	Piezas test;
	Piece shouldBeX = test.dropPiece(0);
	shouldBeX = test.pieceAt(0, 0);
	ASSERT_EQ(shouldBeX, X);
}

TEST(PiezasTest, validPieceAtO)
{
	Piezas test;
	Piece shouldBeO = test.dropPiece(0);
	shouldBeO = test.dropPiece(0);
	shouldBeO = test.pieceAt(1, 0);
	ASSERT_EQ(shouldBeO, O);
}

TEST(PiezasTest, validPiecePlaceX)
{
	Piezas test;
	Piece shouldBeX = test.dropPiece(0);
	shouldBeX = test.dropPiece(0);
	shouldBeX = test.dropPiece(0);
	shouldBeX = test.pieceAt(2, 0);
	ASSERT_EQ(shouldBeX, X);
}

TEST(PiezasTest, validPiecePlaceO)
{
	Piezas test;
	Piece shouldBeO = test.dropPiece(0);
	shouldBeO = test.dropPiece(0);
	shouldBeO = test.dropPiece(2);
	shouldBeO = test.dropPiece(2);
	shouldBeO = test.pieceAt(1, 2);
	ASSERT_EQ(shouldBeO, O);
}

TEST(PiezasTest, gameStateInvalid)
{
	Piezas test;
	Piece shouldBeInvalid = test.gameState();
	ASSERT_EQ(shouldBeInvalid, Invalid);
}

TEST(PiezasTest, xWinsRows)
{
	Piezas test;
	Piece shouldBeX = test.dropPiece(0);
	shouldBeX = test.dropPiece(0);
	shouldBeX = test.dropPiece(1);
	shouldBeX = test.dropPiece(1);
	shouldBeX = test.dropPiece(2);
	shouldBeX = test.dropPiece(0);
	shouldBeX = test.dropPiece(3);
	shouldBeX = test.dropPiece(3);
	shouldBeX = test.dropPiece(2);
	shouldBeX = test.dropPiece(2);
	shouldBeX = test.dropPiece(1);
	shouldBeX = test.dropPiece(3);
	shouldBeX = test.gameState();
	ASSERT_EQ(shouldBeX, X);
}

TEST(PiezasTest, oWinsRows)
{
	Piezas test;
	Piece shouldBeO = test.dropPiece(0);
	shouldBeO = test.dropPiece(0);
	shouldBeO = test.dropPiece(0);
	shouldBeO = test.dropPiece(2);
	shouldBeO = test.dropPiece(1);
	shouldBeO = test.dropPiece(1);
	shouldBeO = test.dropPiece(3);
	shouldBeO = test.dropPiece(2);
	shouldBeO = test.dropPiece(3);
	shouldBeO = test.dropPiece(3);
	shouldBeO = test.dropPiece(1);
	shouldBeO = test.dropPiece(2);
	shouldBeO = test.gameState();
	ASSERT_EQ(shouldBeO, O);
}

TEST(PiezasTest, tieOnRows)
{
	Piezas test;
	Piece tie = test.dropPiece(0);
	tie = test.dropPiece(0);
	tie = test.dropPiece(0);

	tie = test.dropPiece(3);
	tie = test.dropPiece(1);
	tie = test.dropPiece(1);

	tie = test.dropPiece(1);
	tie = test.dropPiece(3);
	tie = test.dropPiece(3);

	tie = test.dropPiece(2);
	tie = test.dropPiece(2);
	tie = test.dropPiece(2);

	tie = test.gameState();
	ASSERT_EQ(tie, Blank);
}

TEST(PiezasTest, xWinsCols)
{
	Piezas test;
	Piece shouldBeX = test.dropPiece(0);
	shouldBeX = test.dropPiece(1);
	shouldBeX = test.dropPiece(0);
	shouldBeX = test.dropPiece(3);
	shouldBeX = test.dropPiece(2);
	shouldBeX = test.dropPiece(3);
	shouldBeX = test.dropPiece(0);
	shouldBeX = test.dropPiece(2);
	shouldBeX = test.dropPiece(1);
	shouldBeX = test.dropPiece(1);
	shouldBeX = test.dropPiece(3);
	shouldBeX = test.dropPiece(2);
	shouldBeX = test.gameState();
	ASSERT_EQ(shouldBeX, X);
}

TEST(PiezasTest, oWinsCols)
{
	Piezas test;
	Piece shouldBeO = test.dropPiece(1);
	shouldBeO = test.dropPiece(0);
	shouldBeO = test.dropPiece(3);
	shouldBeO = test.dropPiece(2);
	shouldBeO = test.dropPiece(3);
	shouldBeO = test.dropPiece(0);
	shouldBeO = test.dropPiece(2);
	shouldBeO = test.dropPiece(1);
	shouldBeO = test.dropPiece(1);
	shouldBeO = test.dropPiece(3);
	shouldBeO = test.dropPiece(2);
	shouldBeO = test.dropPiece(0);
	shouldBeO = test.gameState();
	ASSERT_EQ(shouldBeO, O);
}

TEST(PiezasTest, tieOnCols)
{
	Piezas test;
	Piece tie = test.dropPiece(0);
	tie = test.dropPiece(1);
	tie = test.dropPiece(0);
	tie = test.dropPiece(3);
	tie = test.dropPiece(2);
	tie = test.dropPiece(3);
	tie = test.dropPiece(0);
	tie = test.dropPiece(2);
	tie = test.dropPiece(1);
	tie = test.dropPiece(1);
	tie = test.dropPiece(2);
	tie = test.dropPiece(3);
	tie = test.gameState();
	ASSERT_EQ(tie, Blank);
}
