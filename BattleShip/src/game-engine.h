#pragma once
#include <vector>
using std::vector;

vector <vector<char>> GenerateRandomBoard();
vector <vector<char>> PlayHorizontally(int size, vector <vector<char>> board);
vector <vector<char>> PlayVertically(int size, vector <vector<char>> board);
std::tuple<int, int> CalculateEnemyMove();
vector <vector<char>> getNewBoard();