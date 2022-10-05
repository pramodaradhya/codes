#pragma once
#include <bits/stdc++.h>
using namespace std;

class Player {
public:
	char id;
	string name;

public:
	void printBoard(char board[][10]) {
		int rows = 6, col = 7;
		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= col; j++) {
				if (board[i][j] != 'R' && board[i][j] != 'B') {
					board[i][j] = ' ';
				}

				cout << "|";
				cout << board[i][j];
			}

			cout << "|" << endl;
		}
		cout << endl;
	}

	bool winCheck(char board[][10], Player active) {
		char activeID = active.id;
		bool win = false;

		for (int i = 6; i >= 1; i--) {
			for (int j = 7; j >= 1; j--) {
				if (board[i][j] == activeID &&
					board[i - 1][j - 1] == activeID &&
					board[i - 2][j - 2] == activeID &&
					board[i - 3][j - 3] == activeID) {
					win = true;
				}

				if (board[i][j] == activeID && board[i][j - 1] == activeID &&
					board[i][j - 2] == activeID &&
					board[i][j - 3] == activeID) {
					win = true;
				}

				if (board[i][j] == activeID && board[i - 1][j] == activeID &&
					board[i - 2][j] == activeID &&
					board[i - 3][j] == activeID) {
					win = true;
				}

				if (board[i][j] == activeID &&
					board[i - 1][j + 1] == activeID &&
					board[i - 2][j + 2] == activeID &&
					board[i - 3][j + 3] == activeID) {
					win = true;
				}

				if (board[i][j] == activeID && board[i][j + 1] == activeID &&
					board[i][j + 2] == activeID &&
					board[i][j + 3] == activeID) {
					win = true;
				}
			}
		}
		return win;
	}

	int fullBoard(char board[][10]) {
		int full = 0;
		for (int i = 1; i <= 7; i++) {
			if (board[1][i] != ' ') {
				full++;
			}
		}
		return full;
	}
};