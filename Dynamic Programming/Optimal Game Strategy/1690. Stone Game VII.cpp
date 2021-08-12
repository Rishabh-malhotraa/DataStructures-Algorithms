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
  int stoneGameVII(vector<int> &stones)
  {
    int n = stones.size();
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      prefixSum[i] = prefixSum[i - 1] + stones[i - 1];

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int gap = 1; gap < n; gap++)
    {
      for (int i = 0, j = gap; j < n; j++, i++)
      {
        int start = prefixSum[j + 1] - prefixSum[i + 1];
        int end = prefixSum[j] - prefixSum[i];

        dp[i][j] = max(start - dp[i + 1][j], end - dp[i][j - 1]);
      }
    }
    return dp[0][n - 1];
  }
};