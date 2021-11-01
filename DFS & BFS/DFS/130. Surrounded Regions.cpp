/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  void solve(vector<vector<char>> &board)
  {
    if (board.empty())
      return;

    m = board.size(), n = board[0].size();

    for (int i = 0; i < m; i++)
    {
      if (board[i][0] == 'O')
        sudoWalls(board, i, 0);

      if (board[i][n - 1] == 'O')
        sudoWalls(board, i, n - 1);
    }

    for (int j = 0; j < n; j++)
    {
      if (board[0][j] == 'O')
        sudoWalls(board, 0, j);
      if (board[m - 1][j] == 'O')
        sudoWalls(board, m - 1, j);
    }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        board[i][j] = (board[i][j] == 'R') ? 'O' : 'X';
  }

  void sudoWalls(vector<vector<char>> &board, int i, int j)
  {
    board[i][j] = 'R';

    for (vector<int> &d : dir)
    {
      int ni = i + d[0];
      int nj = j + d[1];

      if (isValid(ni, nj) && board[ni][nj] == 'O')
        sudoWalls(board, ni, nj);
    }
  }
};