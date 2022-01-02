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
  int strangePrinter(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, n));
    for (int gap = 0; gap < n; gap++)
    {
      for (int i = 0, j = gap; j < n; i++, j++)
      {
        if (gap == 0)
        {
          dp[i][j] = 1;
        }
        else if (gap == 1)
        {
          dp[i][j] = (s[i] == s[j]) ? 1 : 2;
        }
        else
        {
          dp[i][j] = INT_MAX;
          for (int k = i; k < j; k++)
          {
            /*
               |
              aba
            */
            int cost = dp[i][k] + dp[k + 1][j];
            dp[i][j] = min(dp[i][j], cost);
          }

          if (s[i] == s[j])
            dp[i][j]--;
        }
      }
    }
    return dp[0][n - 1];
  }
};
