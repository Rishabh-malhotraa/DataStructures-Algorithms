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
  int getMoneyAmount(int n)
  {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int gap = 1; gap <= n; gap++)
    {
      for (int i = 1, j = gap; j <= n; i++, j++)
      {
        if (gap == 1)
          dp[i][j] = 0;
        else if (gap == 2)
        {
          dp[i][j] = min(i, j);
        }
        else
        {
          int maxMoneyRequired = INT_MAX;
          for (int k = i; k <= j; k++)
          {
            int left = (k == i) ? 0 : dp[i][k - 1];
            int right = (k == j) ? 0 : dp[k + 1][j];
            int cost = max(left, right);
            maxMoneyRequired = min(maxMoneyRequired, k + cost);
          }
          dp[i][j] = maxMoneyRequired;
        }
      }
    }

    return dp[1][n];
  }
};