/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Could also be solved using Disjoint Set

class Solution
{
public:
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  int minimumEffortPath(vector<vector<int>> &heights)
  {
    m = heights.size(), n = heights[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0});

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = INT_MAX;
    while (!pq.empty())
    {
      auto curr = pq.top();
      pq.pop();

      int effort = curr[0], i = curr[1], j = curr[2];

      if (i == m - 1 && j == n - 1)
        return effort;

      for (vector<int> &d : dir)
      {
        int ni = i + d[0], nj = j + d[1];
        if (isValid(ni, nj))
        {
          int new_effort = max(effort, abs(heights[ni][nj] - heights[i][j]));
          if (dp[ni][nj] > new_effort)
          {
            dp[ni][nj] = new_effort;
            pq.push({new_effort, ni, nj});
          }
        }
      }
    }
    return -1;
  }
};