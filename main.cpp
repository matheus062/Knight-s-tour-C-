#include <iostream>
#include "src/KnightBruteForce/KnightBruteForce.h"
#include "src/KnightWarnsdorff/KnightWarnsdorff.h"

int main() {
	KnightBruteForce knightBrute;
	KnightWarnsdorff knightWarnsdorff;
	int xStart = 0, yStart = 0;

	std::cout << "Escolha a posicao X inicial: ";
	std::cin >> xStart;
	std::cout << "Escolha a posicao Y inicial: ";
	std::cin >> yStart;

	std::cout << std::endl << "Iniciando Forca Bruta..." << std::endl;

	if (knightBrute.run(xStart, yStart)) {
		knightBrute.printResult();
	}
	else {
		std::cout << "Solucao nao encontrada.";
	}

	std::cout << std::endl << std::endl << "Iniciando Warnsdorff's..." << std::endl;

	if (knightWarnsdorff.run(xStart, yStart)) {
		knightWarnsdorff.printResult();
	}
	else {
		std::cout << "Solucao nao encontrada.";
	}

	return 0;
}