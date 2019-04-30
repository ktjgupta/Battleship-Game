#include <stdlib.h> 
#include <map>
#include <chrono>
#include <thread>
#include "game-engine.h"
#include "ofMain.h"

using std::vector;
using std::map;
using namespace std::this_thread;
using namespace std::chrono;

const int kWidth = 10;
const char kBlankChar = '_';
vector<vector<char> > guess_board(kWidth, vector<char>(kWidth, kBlankChar));
map<char, int> ships = { {'a', 5}, {'b', 4}, {'c', 3}, {'s', 3}, {'d', 2} };

/* Method that generates a random board with given ship sizes */
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

/* Sub method of GenerateBoard. Places one ship horizontally randomly */
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

/* Sub method of GenerateBoard. Places one ship vertically randomly */
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

/* Sub method of GenerateBoard. Places one ship horizontally randomly */
vector <vector<char>> getNewBoard() {
	vector <vector<char>> board = GenerateRandomBoard();
	return board;
}

/* Method that guesses a random number that coincides as enemy move*/
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

/*Method that checks to see if there are any more ships on board*/
bool CheckIfWon(vector <vector<char>> board) {
	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			if (board[i][j] == 'S') {
				return false;
			}
		}
	}
	return true;
}

/*Method that checks to see if the coordinates picked by user is a valid location for ship*/
char ValidatePlacement(int size, int init_x, int init_y, int fin_x, 
	int fin_y, vector<vector<char>> player_board) {

	if ((init_x != fin_x) && (init_y != fin_y)) {
		return kBlankChar;
	}
	else if (init_x == fin_x) {
		if (abs(init_y - fin_y) != size - 1) {
			return kBlankChar;
		}
		for (int y = init_y; y <= fin_y; y++) {
			if (player_board[init_x][y] == 'S') {
				return kBlankChar;
			}
		}
		return 'H';
	}
	else {
		if (abs(init_x - fin_x) != size - 1) {
			return kBlankChar;
		}
		for (int x = init_x; x <= fin_x; x++) {
			if (player_board[x][init_y] == 'S') {
				return kBlankChar;
			}
		}
		return 'V';
	}

	
}

/*Given the ship is valid, places ship on board and returns the board*/
vector <vector<char>> PlaceShip(vector <vector<char>> player_board, char orient, 
	int init_x, int init_y, int size, GameBoard &p_board) {
		
	if (orient == 'H') {
		for (int y = 0; y < size; y++) {
			player_board[init_x][init_y + y] = 'S';
			p_board.display_board[init_x][init_y + y].color = ofColor::green;
		}
	}
	else {
		for (int x = 0; x < size; x++) {
			player_board[init_x + x][init_y] = 'S';
			p_board.display_board[init_x + x][init_y].color = ofColor::green;
		}
	}
	return player_board;
}

/* Method that swaps the 2 coordinates if final is less than initial*/
void SwapCoords(int &init_x, int &init_y, int &fin_x, int &fin_y) {
	if (fin_x < init_x) {
		int temp = fin_x;
		fin_x = init_x;
		init_x = temp;
	}
	if (fin_y < init_y) {
		int temp = fin_y;
		fin_y = init_y;
		init_y = temp;
	}
}