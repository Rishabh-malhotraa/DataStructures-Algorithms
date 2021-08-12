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
  int mincostTickets(vector<int> &days, vector<int> &cost)
  {
    unordered_set<int> keys(days.begin(), days.end());
    vector<int> dp(366, 0);
    for (int i = 1; i < 366; i++)
      if (keys.find(i) == keys.end())
        dp[i] = dp[i - 1];
      else
        dp[i] = min({dp[i - 1] + cost[0], dp[max(0, i - 7)] + cost[1], dp[max(0, i - 30)] + cost[2]});

    return dp[days.back()];
  }
};