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
  int maxCost = INT_MAX;
  vector<vector<int>> dp;
  int dfs(int idx, int mask, vector<vector<int>> &workers, vector<vector<int>> &bikes)
  {
    if (idx == workers.size())
      return 0;

    if (dp[idx][mask] != -1)
      return dp[idx][mask];

    int minCost = INT_MAX;
    for (int i = 0; i < bikes.size(); i++)
    {
      int occupied = mask & (1 << i);

      if (occupied)
        continue;

      int cost = abs(workers[idx][0] - bikes[i][0]) + abs(workers[idx][1] - bikes[i][1]);
      cost += dfs(idx + 1, (mask | (1 << i)), workers, bikes);
      minCost = min(minCost, cost);
    }
    return dp[idx][mask] = minCost;
  }

public:
  int assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes)
  {
    int n = bikes.size(), m = workers.size();
    dp.assign(m, vector<int>(1 << n, -1));

    return dfs(0, 0, workers, bikes);
  }
};