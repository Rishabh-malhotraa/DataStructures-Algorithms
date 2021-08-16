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
  int maxCoins(vector<int> &arr)
  {
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int gap = 0; gap < n; gap++)
    {
      for (int i = 0, j = gap; j < n; j++, i++)
      {
        for (int k = i; k <= j; k++)
        {
          int left = (k == i) ? 0 : dp[i][k - 1];
          int right = (k == j) ? 0 : dp[k + 1][j];
          int middle = ((i == 0) ? 1 : arr[i - 1]) * ((j == n - 1) ? 1 : arr[j + 1]) * arr[k];
          dp[i][j] = max(dp[i][j], left + right + middle);
        }
      }
    }
    return dp[0][n - 1];
  }
};