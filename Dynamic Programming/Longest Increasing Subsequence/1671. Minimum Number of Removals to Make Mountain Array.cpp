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
  vector<int> getSubsequence(vector<int> nums, bool isDecreasing = false)
  {
    int n = nums.size();
    if (isDecreasing == true)
      reverse(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (nums[j] < nums[i])
          dp[i] = max(dp[i], 1 + dp[j]);
      }
    }

    if (isDecreasing)
      reverse(dp.begin(), dp.end());

    return dp;
  }

  int minimumMountainRemovals(vector<int> &nums)
  {
    // LIS
    int n = nums.size();
    vector<int> lis = getSubsequence(nums, false);
    vector<int> lds = getSubsequence(nums, true);

    int maxSequence = 1;

    for (int i = 0; i < n; i++)
      if (lis[i] > 1 && lds[i] > 1)
        maxSequence = max(maxSequence, lis[i] + lds[i] - 1);

    return n - maxSequence;
  }
};
