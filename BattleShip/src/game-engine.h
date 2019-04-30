#pragma once
#include <vector>
using std::vector;

vector <vector<char>> GenerateRandomBoard();
vector <vector<char>> PlayHorizontally(int size, vector <vector<char>> board);
vector <vector<char>> PlayVertically(int size, vector <vector<char>> board);
std::tuple<int, int> CalculateEnemyMove();
vector <vector<char>> getNewBoard();
bool CheckIfWon(vector <vector<char>> board);
char ValidatePlacement(int size, int init_x, int init_y, int fin_x, int fin_y, vector<vector<char>> player_board);
vector <vector<char>> PlaceShip(vector <vector<char>> player_board, char orient, int init_x, int init_y, int size);