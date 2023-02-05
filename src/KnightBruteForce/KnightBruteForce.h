#pragma once
#include "../Constants.h";

class KnightBruteForce
{
public:
	KnightBruteForce();
	bool run(int xStart, int yStart);
	void printResult();

private:
	int board[Constants::SIZE][Constants::SIZE];
	int moves;
	int startTime;
	int endTime;

	int const xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int const yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	bool knightsTour(int x, int y, int pos);
};

