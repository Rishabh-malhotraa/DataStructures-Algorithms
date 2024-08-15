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
  int findMaximumLength(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0), dp(n + 1, 0), last(n + 1, 0);

    for (int i = 1; i <= n; i++)
      prefixSum[i] = prefixSum[i - 1] + nums[i];

    for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        int subSegmentSum = prefixSum[i] - prefixSum[j];
        if (last[j] >= subSegmentSum)
        {
          dp[i] = 1 + dp[j];
          last[i] = subSegmentSum;
        }
      }
    }
    return dp[n];
  }
};