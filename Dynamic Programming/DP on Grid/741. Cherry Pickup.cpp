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
public:
  int cherryPickup(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MIN)));

    dp[1][1][1] = grid[0][0];

    for (int x1 = 1; x1 <= n; x1++)
    {
      for (int y1 = 1; y1 <= n; y1++)
      {
        for (int x2 = 1; x2 <= n; x2++)
        {
          int y2 = x1 + y1 - x2;

          if (dp[x1][y1][x2] > 0 || y2 < 1 || y2 > n || grid[x1 - 1][y1 - 1] == -1 || grid[x2 - 1][y2 - 1] == -1)
            continue;

          int curr = max({dp[x1 - 1][y1][x2], dp[x1 - 1][y1][x2 - 1], dp[x1][y1 - 1][x2], dp[x1][y1 - 1][x2 - 1]});

          if (curr < 0)
            continue;

          dp[x1][y1][x2] = curr + grid[x1 - 1][y1 - 1];
          if (x1 != x2)
            dp[x1][y1][x2] += grid[x2 - 1][y2 - 1];
        }
      }
    }
    return (dp[n][n][n] < 0 ? 0 : dp[n][n][n]);
  }
};