#include "GameBoard.h"
const int kTileWidth = 72;
const int kTileSep = 5;
const int kWidth = 10;
void GameBoard::MakeBoard(int set_x, int set_y) {
	GameSquare myRect;
	vector<vector<GameSquare> > board(kWidth, vector<GameSquare>(kWidth, myRect));
	display_board = board;
	int y = set_y;
	for (int i = 0; i < kWidth; i++) {
		int x = set_x;
		for (int j = 0; j < kWidth; j++) {
			GameSquare square;
			square.rect.set(x, y, kTileWidth, kTileWidth);
			square.color = ofColor::blue;
			square.name = to_string(i) + to_string(j);
			display_board[i][j] = square;
			x += kTileWidth + kTileSep;
		}
		y += kTileWidth + kTileSep;
	}
}

void GameBoard::draw() {
	for (int i = 0; i < kWidth; i++) {
		for (int j = 0; j < kWidth; j++) {
			ofSetColor(display_board[i][j].color);
			ofDrawRectangle(display_board[i][j].rect);
		}
	}
}
