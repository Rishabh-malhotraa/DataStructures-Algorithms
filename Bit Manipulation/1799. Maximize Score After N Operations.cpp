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
  int n;
  vector<unordered_map<int, int>> dp;
  int dfs(vector<int> &nums, int i, int mask)
  {
    if (i > (n / 2))
      return 0;

    if (dp[i].find(mask) != dp[i].end())
      return dp[i][mask];

    int cost = 0;
    for (int j = 0; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        int new_mask = (1 << j) | (1 << k);

        if (((1 << j) & mask) && ((1 << k) & mask))
        {
          int value = i * __gcd(nums[j], nums[k]);
          cost = max(cost, value + dfs(nums, i + 1, mask ^ new_mask));
        }
      }
    }
    return dp[i][mask] = cost;
  }

public:
  int maxScore(vector<int> &nums)
  {
    n = nums.size();
    dp.resize(n);
    return dfs(nums, 1, (1 << n) - 1);
  }
};