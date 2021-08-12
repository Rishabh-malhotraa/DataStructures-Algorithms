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
  int stoneGameII(vector<int> &piles)
  {
    int n = piles.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> suffixSum(n, 0);
    int sum = accumulate(piles.begin(), piles.end(), 0);
    suffixSum[0] = sum;

    for (int i = 1; i < n; i++)
      suffixSum[i] = suffixSum[i - 1] - piles[i - 1];

    for (int i = 0; i < n; i++)
      dp[i][n] = suffixSum[i];

    for (int i = n - 1; i >= 0; i--)
    {
      for (int M = n - 1; M >= 1; M--)
      {
        for (int X = 1; X <= 2 * M && i + X <= n; X++)
        {
          dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + X][max(M, X)]);
        }
      }
    }

    return dp[0][1];
  }
};