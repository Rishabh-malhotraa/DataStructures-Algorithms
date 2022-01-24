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
  long long mostPoints(vector<vector<int>> &questions)
  {
    int n = questions.size();
    vector<long long> dp(n, 0);

    dp[n - 1] = questions.back()[0];
    for (int i = n - 2; i >= 0; i--)
    {
      long long points = questions[i][0];
      int skip = questions[i][1] + 1;

      long long cost = (i + skip >= n) ? 0 : dp[i + skip];

      dp[i] = max(dp[i + 1], points + cost);
    }

    // for (int el : dp)
    //   cout << el << " ";
    // cout << endl;

    return dp.front();
  }
};