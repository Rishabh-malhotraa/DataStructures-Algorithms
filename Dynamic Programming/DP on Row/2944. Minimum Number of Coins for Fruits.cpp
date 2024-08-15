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
  int minimumCoins(vector<int> &prices)
  {
    int n = prices.size();
    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i++)
    {
      dp[i] = prices[i] + dp[i + 1];
      for (int x = 1; (i + x) < n && x < i + 1; x++)
      {
        dp[i] = min(dp[i], prices[i] + dp[i + x]);
      }
    }
    return dp.front();
  }
};

/*





3 1 2





*/