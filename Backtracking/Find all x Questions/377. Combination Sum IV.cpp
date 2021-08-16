//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Count ways of Knapsack

class Solution
{
public:
  int combinationSum4(vector<int> &nums, int target)
  {
    // basic Unbounded knapsack
    int n = nums.size();

    if (n == 0)
      return 0;

    vector<unsigned int> dp(target + 1, 0);

    // loop through sum and try every combination of the elemdents for that sum
    dp[0] = 1;

    for (int i = 1; i < target + 1; i++)
      for (int j = 0; j < n; j++)
        if (i - nums[j] >= 0)
          dp[i] += dp[i - nums[j]];

    return dp[target];
  }
};