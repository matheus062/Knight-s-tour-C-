#include <iostream>
#include "src/KnightBruteForce/KnightBruteForce.h"

int main() {
	KnightBruteForce knightBrute;

	if (knightBrute.run(0, 0)) {
		knightBrute.printResult();
	}
	else {
		std::cout << "Solução não encontrada.";
	}

	return 0;
}