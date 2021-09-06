/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/* BITMASKING -> BECAUSE YOU REMOVE CERTAIN ELEMENT FROM A SET

* Recursive DFS SOLUTION
* YOU NEED TO CHECK FOR ALL AVAILABLE PAIRS DURING RECURSSION


*/

class Solution
{
public:
  vector<unordered_map<int, int>> dp;
  int dfs(vector<int> &n, int i, int mask)
  {
    if (i > n.size() / 2)
      return 0;

    if (dp[i].find(mask) != dp[i].end())
      return dp[i][mask];

    int cost = 0;
    for (int j = 0; j < n.size(); ++j)
      for (auto k = j + 1; k < n.size(); ++k)
      {
        int new_mask = (1 << j) + (1 << k);
        if ((mask & new_mask) == 0)
          cost = max(cost, i * __gcd(n[j], n[k]) + dfs(n, i + 1, mask + new_mask));
      }
    return dp[i][mask] = cost;
  }

  int maxScore(vector<int> &n)
  {
    dp.resize(n.size() + 1);
    return dfs(n, 1, 0);
  }
};
