#pragma once
#include <vector>
using std::vector;

void GenerateRandomBoard();
vector <vector<char>> PlayHorizontally(int size, vector <vector<char>> board);
vector <vector<char>> PlayVertically(int size, vector <vector<char>> board);