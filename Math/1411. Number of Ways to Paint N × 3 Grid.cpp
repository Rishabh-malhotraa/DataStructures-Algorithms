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
  int numOfWays(int n)
  {
    long long mod = 1e9 + 7;
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0LL));
    dp[1][0] = dp[1][1] = 6;
    for (int i = 2; i <= n; i++)
    {
      dp[i][0] = (dp[i - 1][0] * 3 + dp[i - 1][1] * 2) % mod;
      dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1] * 2) % mod;
    }
    return (dp[n][0] + dp[n][1]) % mod;
  }
};