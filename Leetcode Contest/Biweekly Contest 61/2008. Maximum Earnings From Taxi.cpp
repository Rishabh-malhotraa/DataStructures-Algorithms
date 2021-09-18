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
  long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
  {
    long long result = 0;

    sort(rides.begin(), rides.end());

    vector<long long> dp(n + 1, 0);

    dp[0] = 0;
    int idx = 0;
    int i = 1;
    while (i <= n && idx < rides.size())
    {
      int start = rides[idx][0], end = rides[idx][1], tip = rides[idx][2];

      if (i < start)
      {
        dp[i] = max(dp[i - 1], dp[i]);
        i++;
      }
      else if (i == start)
      {
        idx++;
        dp[i] = max(dp[i - 1], dp[i]);
        dp[end] = max(dp[end], dp[i] + end - start + tip);
        result = max(result, dp[end]);
      }
    }
    return result;
  }
};