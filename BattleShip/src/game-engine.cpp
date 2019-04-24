#include <stdlib.h> 
#include <map>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "game-engine.h"

using std::vector;
using std::map;
using namespace std::this_thread;
using namespace std::chrono;

const int kWidth = 10;
const char kBlankChar = '_';
vector<vector<char> > guess_board(kWidth, vector<char>(kWidth, kBlankChar));
map<char, int> ships = { {'a', 5}, {'b', 4}, {'c', 3}, {'s', 3}, {'d', 2} };

vector <vector<char>> GenerateRandomBoard() {

	vector<vector<char> > board(kWidth, vector<char>(kWidth, kBlankChar));
	for (std::map<char, int>::iterator it = ships.begin(); it != ships.end(); ++it) {
		int vert_or_hor = rand() % 2;
		if (vert_or_hor == 0) {
			board = PlayHorizontally(it->second, board);
		}
		else {
			board = PlayVertically(it->second, board);
		}
	}
	return board;

}

vector <vector<char>> PlayHorizontally(int size, vector <vector<char>> board) {
	int row;
	vector<int> valid_positions;
	while (true) {
		row = rand() % kWidth;
		valid_positions.clear();
		for (int i = 0; i < kWidth - size; i++) {
			bool is_valid = true;
			for (int j = i; j < (i + size); j++) {
				if (board[row][j] != kBlankChar) {
					is_valid = false;
				}
			}
			if (is_valid) {
				valid_positions.push_back(i);
			}
		}
		if (valid_positions.size() > 0) {
			break;
		}
	}

	int rand_position = rand() % valid_positions.size();
	int col = valid_positions[rand_position];
	for (int i = 0; i < size; i++) {
		board[row][col] = 'S';
		col++;
	}
	return board;
}

vector <vector<char>> PlayVertically(int size, vector <vector<char>> board) {
	vector<int> valid_positions;
	int col;
	while (true) {
		col = rand() % kWidth;
		valid_positions.clear();
		for (int i = 0; i < kWidth - size; i++) {
			bool is_valid = true;
			for (int j = i; j < (i + size); j++) {
				if (board[j][col] != kBlankChar) {
					is_valid = false;
				}
			}
			if (is_valid) {
				valid_positions.push_back(i);
			}
		}
		if (valid_positions.size() > 0) {
			break;
		}
	}

	int rand_position = rand() % valid_positions.size();
	int row = valid_positions[rand_position];
	for (int i = 0; i < size; i++) {
		board[row][col] = 'S';
		row++;
	}
	return board;
}

vector <vector<char>> getNewBoard() {
	vector <vector<char>> board = GenerateRandomBoard();
	return board;
}

void RunGame() {
	vector <vector<char>> enemy_board = GenerateRandomBoard();

}

std::tuple<int, int> CalculateEnemyMove() {
	sleep_for(seconds(1));
	int x, y;
	while (true) {
		x = rand() % kWidth;
		y = rand() % kWidth;
		if (guess_board[x][y] == kBlankChar) {
			break;
		}
	}
	guess_board[x][y] = 'g';
	return { x,y };
	
}