#include <iostream>
#include "src/KnightBruteForce/KnightBruteForce.h"

int main() {
	KnightBruteForce knightBrute;

	if (knightBrute.run(0, 0)) {
		knightBrute.printResult();
	}
	else {
		std::cout << "Solu��o n�o encontrada.";
	}

	return 0;
}