#include <iostream>

using namespace std;

int const SIZE = 8;
int const xMove[SIZE] = {1, 2, 2, 1, -1, -2, -2, -1};
int const yMove[SIZE] = {2, 1, -1, -2, -2, -1, 1, 2};

struct KnightResult {
	int moves = 0;
	int execTime = 0;
};

void print(int matrix[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << ' ';
		}

		cout << endl;
	}

}

bool trial_error(int board[SIZE][SIZE], int x, int y, int pos) {
	//KnightResult result;

	if (pos == 64) {
		return true;
	}
	
	system("cls");
	print(board);

	bool run;

	int xNext = 0;
	int yNext = 0;


	if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE) && (board[x][y] == 0)) {

		board[x][y] = pos;
		pos++;

		for (int i = 0; i < SIZE; i++) {
			xNext = x + xMove[i];
			yNext = y + yMove[i];

			// Caso seja falso, tente a nova posição, caso chegue a todas e não consigue
			// Faça o backtracking
			return trial_error(board, xNext, yNext, pos);
		}
	}
	else {
		return false;
	}

	return true;
}




int main()
{
	KnightResult result1;
	int board[SIZE][SIZE];
	fill(*board, *board + 64, 0);

	trial_error(board, 0, 0, 1);

	return 0;
}