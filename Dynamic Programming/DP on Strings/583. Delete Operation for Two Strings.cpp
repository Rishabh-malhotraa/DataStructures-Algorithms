//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// DP on strings

class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
      {
        if (i == 0)
          dp[i][j] = j;
        else if (j == 0)
          dp[i][j] = i;
        else
        {
          if (word1[i - 1] == word2[j - 1])
            dp[i][j] = dp[i - 1][j - 1];
          else
            dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }
    return dp[n][m];
  }
};