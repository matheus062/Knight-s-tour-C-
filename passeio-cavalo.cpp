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

bool trial_error(int board[SIZE][SIZE], int x, int y, int pos) {

	if (pos == 64)
		return true;

	for (int i = 0; i < SIZE; i++) {
		int xNext = x + xMove[i];
		int yNext = y + yMove[i];

		if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE) && (board[xNext][yNext] == 0)) {
			board[xNext][yNext] = pos;

			if (trial_error(board, xNext, yNext, pos + 1))
				return true;

			// Caso seja falso, tente a nova posição, caso chegue a todas e não consigue
			// Faça o backtracking
			board[xNext][yNext] = 0;
		}
	}
	return false;
}




int main()
{
	KnightResult result1;
	int board[SIZE][SIZE];
	fill(*board, *board + 64, 0);

	if (trial_error(board, 0, 0, 1))
		print(board);
	else
		cout << "Não encontrou solução";

	return 0;
}