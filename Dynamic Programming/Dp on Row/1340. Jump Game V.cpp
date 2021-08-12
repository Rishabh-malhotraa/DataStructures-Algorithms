//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxJumps(vector<int> &arr, int d)
  {
    int n = arr.size(), maxVal = 0;
    vector<int> dp(n, 1);
    vector<pair<int, int>> nums;
    for (int i = 0; i < n; i++)
      nums.push_back({arr[i], i});

    sort(nums.begin(), nums.end());

    for (pair<int, int> el : nums)
    {
      int idx = el.second, val = el.first;

      for (int j = idx + 1; j <= min(idx + d, n - 1) && arr[j] < arr[idx]; j++)
        dp[idx] = max(dp[idx], dp[j] + 1);

      for (int j = idx - 1; j >= max(idx - d, 0) && arr[j] < arr[idx]; j--)
        dp[idx] = max(dp[idx], dp[j] + 1);

      maxVal = max(maxVal, dp[idx]);
    }
    return maxVal;
  }
};