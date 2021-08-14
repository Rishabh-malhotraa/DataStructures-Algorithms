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
  int maxProfit(int k, vector<int> &prices)
  {
    int n = prices.size();
    if (n == 0)
      return 0;

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; i++)
    {
      int buyPrice = INT_MAX;
      for (int j = 1; j < n; j++)
      {
        buyPrice = min(buyPrice, prices[j - 1] - dp[i - 1][j - 1]);
        dp[i][j] = max(dp[i][j - 1], prices[j] - buyPrice);
      }
    }
    return dp[k][n - 1];
  }
};