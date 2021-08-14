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
#define MEMSET(x) memset(x, 0, sizeof x)

  bool canPartition(vector<int> &arr)
  {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();
    int target = sum / 2;
    bool dp[n + 1][target + 1];
    MEMSET(dp);
    if (sum % 2 == 1)
      return false;

    else
    {
      for (int i = 0; i < n + 1; i++)
      {
        for (int j = 0; j < target + 1; j++)
        {
          if (i == 0 && j != 0)
            dp[i][j] = false;
          // you can alaway get to a subset of sum 0 by not picking up any element
          else if (j == 0)
            dp[i][j] = true;
          else
          {
            dp[i][j] = dp[i - 1][j];

            if (j - arr[i - 1] >= 0)
              dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
          }
        }
      }
    }

    return dp[n][target];
  }
};
