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
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  int maximumMinimumPath(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    priority_queue<vector<int>> pq;
    pq.push({0, 0, 0});

    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
    dp[0][0] = grid[0][0];
    while (!pq.empty())
    {
      auto curr = pq.top();
      pq.pop();

      int minVal = curr[0], i = curr[1], j = curr[2];

      if (i == m - 1 && j == n - 1)
        return minVal;

      for (vector<int> &d : dir)
      {
        int ni = i + d[0], nj = j + d[1];
        if (isValid(ni, nj))
        {
          int newValue = min(minVal, grid[ni][nj]);
          if (dp[ni][nj] < newValue)
          {
            dp[ni][nj] = newValue;
            pq.push({newValue, ni, nj});
          }
        }
      }
    }
    return -1;
  }
};