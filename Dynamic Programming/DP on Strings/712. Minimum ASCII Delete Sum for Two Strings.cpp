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
  int minimumDeleteSum(string s1, string s2)
  {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; j++)
      dp[0][j] = dp[0][j - 1] + s2[j - 1];
    for (int i = 1; i <= m; i++)
    {
      dp[i][0] = dp[i - 1][0] + s1[i - 1];
      for (int j = 1; j <= n; j++)
      {
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
      }
    }
    return dp[m][n];
  }
};

// Clever way of handling all the cases
class Solution
{
public:
  int minimumDeleteSum(string s1, string s2)
  {
    int n = s1.size(), m = s2.size(), result = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
      {
        if (i == 0 && j == 0)
          dp[i][j] = 0;
        else if (i == 0)
          dp[i][j] = dp[i][j - 1] + s2[j - 1];
        else if (j == 0)
          dp[i][j] = dp[i - 1][j] + s1[i - 1];
        else
        {
          int count = (s1[i - 1] == s2[j - 1] ? 0 : s1[i - 1] + s2[j - 1]);
          dp[i][j] = min({dp[i - 1][j] + s1[i - 1],
                          dp[i][j - 1] + s2[j - 1],
                          dp[i - 1][j - 1] + count});
        }
      }
    }
    return dp[n][m];
  }
};