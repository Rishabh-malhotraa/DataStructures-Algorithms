/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class JobAssignment
{

private:
  int dfs(int idx, int mask, vector<vector<int>> &cost, vector<unordered_map<int, int>> &dp)
  {
    if (idx == cost.size())
      return 0;

    if (dp[idx].find(mask) != dp[idx].end())
      return dp[idx][mask];

    int result = INT_MAX;
    for (int i = 0; i < cost.size(); i++)
      if ((1 << i) & mask)
        result = min(result, cost[idx][i] + dfs(idx + 1, mask & !(1 << i), cost, dp));

    return dp[idx][mask] = result;
  }

public:
  int minimumCost(vector<vector<int>> &cost, int n)
  {
    // dp(i, mask)
    vector<unordered_map<int, int>> dp(n);
    int mask = (1 << n) - 1;
    int minimumCost = dfs(0, mask, cost, dp);
    return minimumCost;
  }
};