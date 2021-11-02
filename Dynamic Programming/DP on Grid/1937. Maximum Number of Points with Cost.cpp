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
  long long maxPoints(vector<vector<int>> &points)
  {
    int m = points.size(), n = points[0].size();
    vector<long long> dp(points[0].begin(), points[0].end());

    for (int i = 1; i < m; i++)
    {
      vector<long long> left(n, 0), right(n, 0);

      left[0] = dp[0];
      right[n - 1] = dp[n - 1];

      for (int j = 1; j < n; j++)
        left[j] = max(left[j - 1] - 1, dp[j]);
      for (int j = n - 2; j >= 0; j--)
        right[j] = max(right[j + 1] - 1, dp[j]);

      for (int j = 0; j < n; j++)
        dp[j] = max(left[j], right[j]) + points[i][j];
    }

    return *max_element(dp.begin(), dp.end());
  }
};