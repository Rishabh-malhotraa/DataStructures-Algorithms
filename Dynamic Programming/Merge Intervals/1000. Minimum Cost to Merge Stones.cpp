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
  int mergeStones(vector<int> &stones, int K)
  {
    int n = stones.size();

    if ((n - 1) % (K - 1) != 0)
      return -1;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> sum(n + 1, 0);

    for (int i = 1; i < n + 1; i++)
      sum[i] = sum[i - 1] + stones[i - 1];

    for (int gap = K; gap <= n; gap++)
    {
      for (int i = 0, j = gap - 1; j < n; j++, i++)
      {
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; k += K - 1)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);

        if ((gap - 1) % (K - 1) == 0)
          dp[i][j] += sum[j + 1] - sum[i];
      }
    }
    return dp[0][n - 1];
  }
};