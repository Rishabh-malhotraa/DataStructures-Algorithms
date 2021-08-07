//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Straight forward DFS Questions | Leetcode Bi weekly 58

class Solution
{
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
  int m, n;

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  bool dfs(vector<vector<char>> &board, vector<int> &d, int i, int j, char endColor, char midColor)
  {
    int ni = i + d[0];
    int nj = j + d[1];
    if (isValid(ni, nj) && board[ni][nj] == endColor)
      return true;
    else if (isValid(ni, nj) && board[ni][nj] == midColor)
      return dfs(board, d, ni, nj, endColor, midColor);
    else
      return false;
  }

  bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color)
  {
    m = board.size(), n = board[0].size();
    for (vector<int> &d : dir)
    {
      // now for a given direction do dfs
      char midColor = (color == 'B') ? 'W' : 'B';
      int ni = rMove + d[0];
      int nj = cMove + d[1];

      if (isValid(ni, nj) && board[ni][nj] == midColor)
      {
        bool result = dfs(board, d, ni, nj, color, midColor);
        if (result)
          return result;
      }
    }
    return false;
  }
};