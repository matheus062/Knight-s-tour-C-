#include <iostream>
#include <iomanip>

using namespace std;

int const SIZE = 8;
int const xMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int const yMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };


struct KnightResult {
	int moves = 0;
	int execTime = 0;
};

void print(int matrix[SIZE][SIZE]) {
	system("cls");

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << setw(4) << matrix[i][j] << "|";

		cout << endl;

		if (i != SIZE - 1) {
			for (int k = 0; k < SIZE; k++)
				cout << "  ---";
			cout << endl;
		}
	}
}

bool knights_trial(int board[SIZE][SIZE], int x, int y, int pos) {
	bool nextValid = false;

	board[x][y] = pos;

	if (pos == 64) {
		return true;
	}

	int posNext = pos + 1;

	for (int i = 0; i < SIZE; i++) {
		int xNext = x + xMove[i];
		int yNext = y + yMove[i];

		nextValid = ((xNext >= 0) && (xNext < SIZE) && (yNext >= 0) && (yNext < SIZE) && (board[xNext][yNext] == 0));

		if (nextValid && knights_trial(board, xNext, yNext, posNext)) {
			return true;
		}
	}

	board[x][y] = 0;

	return false;
}

int main() {
	KnightResult result1;
	int board[SIZE][SIZE] = {};
	fill(*board, *board + (SIZE * SIZE), 0);

	// TODO : Implementar a escolha da posição para o usuário

	if (knights_trial(board, 0, 0, 1)) {
		print(board);
	}
	else {
		cout << "Não encontrou solução";
	}

	return 0;
}