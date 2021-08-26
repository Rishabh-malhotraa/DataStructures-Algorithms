//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

/**
 * BFS 
 * Return the next state given the previous state
 * the follow-up are tough
 * 1. in place (all transition happens simulatneoulty and not one after the other)
* 2. Infite grid handle cases at the border?

*/
class Solution
{
private:
  int m, n;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }
  int getChildren(int i, int j, vector<vector<int>> &board)
  {
    int count = 0;
    for (vector<int> &d : dir)
    {
      int ni = i + d[0];
      int nj = j + d[1];

      if (isValid(ni, nj) && board[ni][nj] == 1)
        count++;
    }
    return count;
  }

public:
  void gameOfLife(vector<vector<int>> &board)
  {
    /*
      Any live cell with fewer than two live neighbors dies as if caused by under-population.
      Any live cell with two or three live neighbors lives on to the next generation.
      Any live cell with more than three live neighbors dies, as if by over-population.
      Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    */
    m = board.size(), n = board[0].size();
    auto nextBoard = board;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int children = getChildren(i, j, board);
        if (board[i][j] == 1)
        {
          if (children < 2)
            nextBoard[i][j] = 0;
          if (children > 3)
            nextBoard[i][j] = 0;
        }
        else
        {
          if (children == 3)
            nextBoard[i][j] = 1;
        }
      }
    }
    board = nextBoard;
    return;
  }
};