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
  int coinChange(vector<int> &coins, int amount)
  {
    int n = coins.size(), val = 0;
    vector<int> dp(amount + 1, INT_MAX - 1);

    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
      int val = INT_MAX;
      for (int j = 0; j < coins.size(); j++)
        if (i - coins[j] >= 0)
          val = min(1 + dp[i - coins[j]], val);

      cout << "VAL   --->" << val << endl;
      dp[i] = min(dp[i], val);
    }

    return (dp[amount] == INT_MAX - 1) ? -1 : dp[amount];
  }
};