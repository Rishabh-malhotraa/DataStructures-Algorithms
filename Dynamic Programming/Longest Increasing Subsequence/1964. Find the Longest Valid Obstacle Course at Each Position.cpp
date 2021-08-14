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
  vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
  {
    int n = obstacles.size();
    vector<int> list, dp(n, 1);
    list.push_back(obstacles[0]);
    for (int i = 1; i < n; i++)
    {
      int idx = upper_bound(list.begin(), list.end(), obstacles[i]) - list.begin();
      if (idx == list.size())
      {
        list.push_back(obstacles[i]);
        dp[i] = list.size();
      }
      else
      {
        list[idx] = obstacles[i];
        dp[i] = idx + 1;
      }
    }
    return dp;
  };
};