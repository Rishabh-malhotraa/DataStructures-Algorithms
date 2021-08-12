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
  int minSideJumps(vector<int> &obstacles)
  {
    vector<int> dp = {(int)1e7, 1, 0, 1};

    for (int el : obstacles)
    {
      dp[el] = dp[0];
      for (int i = 1; i <= 3; i++)
      {
        if (i != el)
          dp[i] = min({dp[1] + (i != 1), dp[2] + (i != 2), dp[3] + (i != 3)});
      }
    }
    return *min_element(dp.begin() + 1, dp.end());
  }
};