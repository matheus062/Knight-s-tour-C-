#include "KnightBruteForce.h"
#include <iostream>
#include <iomanip>
#include <chrono>

KnightBruteForce::KnightBruteForce() {
	std::fill(*this->board, *this->board + (Constants::SIZE * Constants::SIZE), 0);
	this->moves = 0;
	this->startTime = 0;
	this->endTime = 0;
}

void KnightBruteForce::printResult() {
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

bool KnightBruteForce::run(int xStart, int yStart) {
	bool result;

	this->startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	result = this->knightsTour(xStart, yStart, 1);
	this->endTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	return result;
}

bool KnightBruteForce::knightsTour(int x, int y, int pos) {
	bool nextValid = false;
	this->board[x][y] = pos;
	this->moves++;

	if (pos == (Constants::SIZE * Constants::SIZE)) {
		return true;
	}

	int posNext = pos + 1;

	for (int i = 0; i < 8; i++) {
		int xNext = x + this->xMove[i];
		int yNext = y + this->yMove[i];
		nextValid = ((xNext >= 0) && (xNext < Constants::SIZE) && (yNext >= 0) && (yNext < Constants::SIZE) && (this->board[xNext][yNext] == 0));

		if (nextValid && this->knightsTour(xNext, yNext, posNext)) {
			return true;
		}
	}

	this->board[x][y] = 0;

	return false;
}