#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

/*

- If a given number is present in a cell
  - then there should not be any duplicates in the same row, same colum and sma subgrid

    123 456 789
    
    row = 0..2 subgrid [i] is 0
    
    j/3  => 
    
    i/3 




// Is just check if the number is present i going to maintain a set for every row every col and every subgrid


vector<set<int>> rows(n)
, cols


1. is just check if the configuration is valid (that would be done by maintaing sets)
2. suppose the configuration is valid -> then check if by filling numeber (this would be done using backtracking) can you get to a valid solution

  

5 3 {1,9}  {X} X X  X X X
7 X X
6 X X
 
X
X
X

9
X
X


1 2 3
4 5 6
7 8 X  X X 9

*/

const int n = 9;

bool isValid(vector<vector<char>> &board, int i, int j, char val)
{
  int row = (i/3)*3, column = (j/3)*3;
  for (int x = 0; x < 9; x++)
    if (board[x][j] == val)
      return false;
  for (int y = 0; y < 9; y++)
    if (board[i][y] == val)
      return false;

  for (int x = 0; x < 3; x++)
    for (int y = 0; y < 3; y++)
      if (board[row + x][column + y] == val)
        return false;
  return true;
}

bool dfs(int idx, vector<vector<char>> &grid)
{
  if (idx == n * n)
  {
    return true;
  }

  int i = idx / n;
  int j = idx % n;

  if (grid[i][j] != '.')
    return dfs(idx + 1, grid);
  else
  {
    for (int k = 1; k <= 9; k++)
    {
      if (isValid(grid, i, j, '0' + k))
      {
        grid[i][j] = '0' + k;
        bool flag = dfs(idx + 1, grid);
        if (flag)
          return true;
        grid[i][j] = '.';
      }
    }
  }

  return false;
}

bool sudokuSolve(const vector<vector<char>> &board)
{
  vector<vector<char>> grid = board;
  return dfs(0, grid);
}

int main()
{

  return 0;
}

// bool isValid(vector<vector<char>> grid)
// {
//   vector<set<int>> rows(n), cols(n), subgrid(n);

//   for (int i = 0; i < n; i++)
//   {
//     for (int j = 0; j < n; j++)
//     {
//       char ch = grid[i][j];

//       int num = ch - '0';

//       int subgrid_i = (i / 3), subgrid_j = j / 3;

//       int idx = (subgrid_i)*3 + subgrid_j;

//       if (ch == '.')
//         continue;

//       if (rows[i].find(num) != rows[i].end())
//         return false;

//       if (cols[i].find(num) != cols[j].end())
//         return false;

//       if (subgrid[idx].find(num) != subgrid[idx].end())
//         return false;

//       rows[i].insert(num);
//       cols[j].insert(num);
//       subgrid[idx].insert(num);
//     }
//   }

//   return true;
// }
