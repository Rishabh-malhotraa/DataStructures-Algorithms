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
private:
  int dp[100005][2][3];
  int mod = 1e9 + 7;
  int countWays(int days, int absent, int late)
  {
    if (late == 3 || absent == 2)
      return 0;
    if (days == 0)
      return 1;

    if (dp[days][absent][late] != -1)
      return dp[days][absent][late];

    long long count = 0;

    count = (count + countWays(days - 1, absent, 0) % mod) % mod; // add P

    count = (count + countWays(days - 1, absent, late + 1) % mod) % mod; // add L

    count = (count + countWays(days - 1, absent + 1, 0) % mod) % mod; // add A

    return dp[days][absent][late] = count;
  }

public:
  int checkRecord(int n)
  {
    // dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    memset(dp, -1, sizeof(dp));

    return countWays(n, 0, 0);
  }
};