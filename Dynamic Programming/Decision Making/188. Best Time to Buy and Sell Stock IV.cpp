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

    int dp[k + 1][n];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i < k + 1; i++)
    {
      int max_el = INT_MIN;
      for (int j = 1; j < n; j++)
      {
        max_el = max(max_el, dp[i - 1][j - 1] - prices[j - 1]);

        dp[i][j] = max(dp[i][j - 1], max_el + prices[j]);
      }
    }

    return dp[k][n - 1];
  }
};