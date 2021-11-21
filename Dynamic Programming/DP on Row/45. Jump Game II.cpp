//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Dynamic | Programming | fibonacci

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int currFarthest = 0, currEnd = 0, n = nums.size(), steps = 0;
    // you want to reach the last step
    for (int i = 0; i < n - 1; i++)
    {
      currFarthest = max(currFarthest, i + nums[i]);

      if (i == currEnd)
      {
        steps++;
        currEnd = currFarthest;
      }
    }
    return steps;
  }
};

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; (j < i + 1 + nums[i]) && j < n; j++)
        dp[j] = min(dp[j], dp[i] + 1);
    }
    return dp[n - 1];
  }
};