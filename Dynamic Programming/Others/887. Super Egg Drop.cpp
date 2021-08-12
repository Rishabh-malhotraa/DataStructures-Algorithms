//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// TLE

class Solution
{
public:
  int superEggDrop(int k, int n)
  {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= k; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i == 1)
          dp[1][j] = j;
        else if (j == 1)
          dp[i][1] = 1;
        else
        {
          // now you have how than two eggs
          dp[i][j] = INT_MAX;
          for (int k = 1; k <= j; k++)
          {
            // eggs * floors
            // break -- no break
            int curr = max(dp[i - 1][k - 1], dp[i][j - k]) + 1;
            // cout << dp[i - 1][k - 1] << " " << dp[i][j - k] << endl;
            dp[i][j] = min(dp[i][j], curr);
          }
        }
      }
    }

    // for(int i = 0; i <= k; i++){
    //   for(int j = 0; j <= n; j++)
    //     cout << dp[i][j] << " ";
    //   cout << endl;
    // }
    // cout << endl;

    return dp[k][n];
  }
};
