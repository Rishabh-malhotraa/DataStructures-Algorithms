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
  int m, n;
  vector<vector<int>> dir = {{0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  int longestLine(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
    int maxVal = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
          for (int idx = 0; vector<int> & d : dir)
          {
            int ni = i + d[0];
            int nj = j + d[1];

            dp[i][j][idx] = isValid(ni, nj) ? dp[ni][nj][idx] + 1 : 1;

            maxVal = max(maxVal, dp[i][j][idx]);
            idx++;
          }
      }
    }
    return maxVal;
  }
};