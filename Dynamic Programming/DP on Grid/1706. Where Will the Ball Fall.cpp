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
private:
  int m, n;
  const int RIGHT = 1, LEFT = -1;
  int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
  {
    if (i == m)
      return j;

    if (dp[i][j] != -2)
      return dp[i][j];

    int turn = grid[i][j];

    if (turn == RIGHT)
    {
      if (j + 1 < n && grid[i][j + 1] == RIGHT)
        return dp[i][j] = dfs(i + 1, j + 1, grid, dp);
    }
    else if (turn == LEFT)
    {
      if (j - 1 >= 0 && grid[i][j - 1] == LEFT)
        return dp[i][j] = dfs(i + 1, j - 1, grid, dp);
    }
    return dp[i][j] = -1;
  }

public:
  vector<int> findBall(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    vector<int> result(n, 0);
    vector<vector<int>> dp(m, vector<int>(n, -2));
    for (int j = 0; j < n; j++)
    {
      result[j] = dfs(0, j, grid, dp);
    }
    return result;
  }
};