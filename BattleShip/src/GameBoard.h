#pragma once
#include "GameSquare.h";
#include <vector>

using std::vector;
class GameBoard {
	public:
		vector<vector<GameSquare>> display_board;
		void MakeBoard(int set_x, int set_y);
		void draw();
};