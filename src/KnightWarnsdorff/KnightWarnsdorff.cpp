#include "KnightWarnsdorff.h"
#include <iostream>
#include <iomanip>
#include <chrono>

KnightWarnsdorff::KnightWarnsdorff() {
	std::fill(*this->board, *this->board + (Constants::SIZE * Constants::SIZE), 0);
	this->moves = 0;
	this->startTime = 0;
	this->endTime = 0;
}

void KnightWarnsdorff::printResult() {
	for (int i = 0; i < Constants::SIZE; i++) {
		for (int j = 0; j < Constants::SIZE; j++) {
			std::cout << std::setw(4) << this->board[i][j] << "|";
		}

		std::cout << std::endl;

		if (i != Constants::SIZE - 1) {
			for (int k = 0; k < Constants::SIZE; k++) {
				std::cout << "  ---";

			}

			std::cout << std::endl;
		}
	}

	std::cout << std::endl << std::endl <<
		"Movimentacoes realizadas: " << this->moves << std::endl <<
		"Tempo de execucao (ms): " << (this->endTime - this->startTime) << std::endl;
}

bool KnightWarnsdorff::run(int xStart, int yStart) {
	bool result;

	this->startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	result = this->knightsTour(xStart, yStart);
	this->endTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	return result;
}

bool KnightWarnsdorff::knightsTour(int x, int y) {
	bool nextValid = false;

	for (int pos = 1; pos <= (Constants::SIZE * Constants::SIZE); pos++) {
		if (!this->nextMove(&x, &y, pos)) {
			return false;
		}
	}

	return true;
}

bool KnightWarnsdorff::nextMove(int* x, int* y, int pos) {
	int xNext;
	int yNext;
	int posNext = -1;
	int degNext = 9;
	int xTemp;
	int yTemp;
	bool validNext = false;
	int current;

	this->board[*x][*y] = pos;
	this->moves++;

	if (pos == 64) {
		return true;
	}

	for (int i = 0; i < 8; ++i) {
		xTemp = (*x + this->xMove[i]);
		yTemp = (*y + this->yMove[i]);
		validNext = this->isValidMove(xTemp, yTemp);
		current = 0;

		for (int j = 0; j < 8; ++j) {
			if (this->isValidMove((xTemp + this->xMove[j]), (yTemp + this->yMove[j]))) {
				current++;
			}
		}

		if (validNext && (current < degNext)) {
			xNext = xTemp;
			yNext = yTemp;
			posNext = i;
			degNext = current;
		}
	}

	if (posNext == -1) {
		return false;
	}

	*x = xNext;
	*y = yNext;

	return true;
}

bool KnightWarnsdorff::isValidMove(int x, int y) {
	return ((x >= 0) && (x < Constants::SIZE) && (y >= 0) && (y < Constants::SIZE) && (this->board[x][y] == 0));
}
