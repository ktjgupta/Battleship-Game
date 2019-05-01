#define CATCH_CONFIG_MAIN
#include "game-engine.h"
#include "catch.hpp";

TEST_CASE("Swap Values Test") {
	int init_x, init_y, fin_x, fin_y;
	SECTION("Final greater than initial") {
		init_x = 2;
		init_y = 3;
		fin_x = 7;
		fin_y = 3;
		SwapCoords(init_x, init_y, fin_x, fin_y);
		REQUIRE(init_x == 2);
		REQUIRE(fin_y == 3);
	}
	SECTION("Final less than initial") {
		init_x = 7;
		init_y = 3;
		fin_x = 2;
		fin_y = 3;
		SwapCoords(init_x, init_y, fin_x, fin_y);
		REQUIRE(init_x == 2);
		REQUIRE(fin_y == 3);
	}
}

TEST_CASE("Valid placement test") {
	int size, init_x, init_y, fin_x, fin_y;
	vector<vector<char>> player_board(10, vector<char>(10, '_'));
	SECTION("Not in right column or row") {
		int size = 2;
		init_x = 3;
		init_y = 4;
		fin_x = 5;
		fin_y = 6;
		char value = ValidatePlacement(size, init_x, init_y, fin_x,
			fin_y, player_board);
		REQUIRE(value == '_');
	}
	SECTION("Not right size (column)") {
		int size = 2;
		init_x = 3;
		init_y = 4;
		fin_x = 3;
		SECTION("Too Big") {
			fin_y = 7;
			char value = ValidatePlacement(size, init_x, init_y, fin_x,
				fin_y, player_board);
			REQUIRE(value == '_');
		}
		SECTION("Too Small") {
			fin_y = 4;
			char value = ValidatePlacement(size, init_x, init_y, fin_x,
				fin_y, player_board);
			REQUIRE(value == '_');
		}
		
	}
	SECTION("Not right size (row)") {
		int size = 2;
		init_x = 3;
		init_y = 4;
		fin_y = 4;
		SECTION("Too Big") {
			fin_x = 7;
			char value = ValidatePlacement(size, init_x, init_y, fin_x,
				fin_y, player_board);
			REQUIRE(value == '_');
		}
		SECTION("Too Small") {
			fin_x = 3;
			char value = ValidatePlacement(size, init_x, init_y, fin_x,
				fin_y, player_board);
			REQUIRE(value == '_');
		}

	}
	SECTION("Ship Overlap (Vertical)") {
		int size = 3;
		init_x = 0;
		init_y = 3;
		fin_y = 2;
		fin_x = 3;
		player_board[1][2] = 'S';
		player_board[1][3] = 'S';
		player_board[1][4] = 'S';
		char value = ValidatePlacement(size, init_x, init_y, fin_x,
			fin_y, player_board);
		REQUIRE(value == '_');
	}
	SECTION("Ship Overlap (Horizontal)") {
		int size = 3;
		init_x = 2;
		init_y = 1;
		fin_y = 3;
		fin_x = 2;
		player_board[2][2] = 'S';
		player_board[3][2] = 'S';
		player_board[4][2] = 'S';
		char value = ValidatePlacement(size, init_x, init_y, fin_x,
			fin_y, player_board);
		REQUIRE(value == '_');
	}
	SECTION("Valid (horizontal)") {
		int size = 4;
		init_x = 8;
		init_y = 4;
		fin_y = 7;
		fin_x = 8;
		char value = ValidatePlacement(size, init_x, init_y, fin_x,
			fin_y, player_board);
		REQUIRE(value == 'H');
	}
	SECTION("Valid (Vertical)") {
		int size = 4;
		init_x = 5;
		init_y = 4;
		fin_y = 4;
		fin_x = 8;
		char value = ValidatePlacement(size, init_x, init_y, fin_x,
			fin_y, player_board);
		REQUIRE(value == 'V');
	}
}

TEST_CASE("Check if Won Test") {
	SECTION("Empty Board") {
		vector<vector<char>> player_board(10, vector<char>(10, '_'));
		REQUIRE(CheckIfWon(player_board));
	}
	SECTION("All S") {
		vector<vector<char>> player_board(10, vector<char>(10, 'S'));
		REQUIRE(!CheckIfWon(player_board));
	}
	SECTION("1 S") {
		vector<vector<char>> player_board(10, vector<char>(10, '_'));
		player_board[2][2] = 'S';
		REQUIRE(!CheckIfWon(player_board));
	}
	SECTION("Multiple S") {
		vector<vector<char>> player_board(10, vector<char>(10, '_'));
		player_board[2][2] = 'S';
		player_board[3][4] = 'S';
		player_board[9][8] = 'S';
		REQUIRE(!CheckIfWon(player_board));
	}
}