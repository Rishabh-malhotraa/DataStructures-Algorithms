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
  int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
  {
    vector<tuple<int, int, int>> jobs;

    for (int i = 0; i < endTime.size(); i++)
      jobs.push_back({endTime[i], startTime[i], profit[i]});

    sort(jobs.begin(), jobs.end());
    map<int, int> dp = {{0, 0}};

    for (auto &[endTime, startTime, profit] : jobs)
    {
      int additionalProfit = prev(dp.upper_bound(startTime))->second;
      int maxProfit = profit + additionalProfit;

      if (maxProfit > dp.rbegin()->second)
        dp[endTime] = maxProfit;
    }
    return dp.rbegin()->second;
  }
};