//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming | Strings | ⭐⭐⭐⭐⭐ | Decision Making

class Solution
{
public:
  bool isMatch(string s, string p)
  {
    int n = p.size();
    int m = s.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
      {
        if (j == 0)
        {
          dp[i][j] = (p[i - 1] == '*' ? dp[i - 2][j] : false);
        }
        else
        {
          if (p[i - 1] == '.')
          {
            dp[i][j] = dp[i - 1][j - 1];
          }
          else if (p[i - 1] == '*')
          {
            bool nil = dp[i - 2][j];
            bool add = (p[i - 2] == s[j - 1] || p[i - 2] == '.') && dp[i][j - 1];

            dp[i][j] = (nil || add);
          }
          else
          {
            dp[i][j] = (p[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : false);
          }
        }
      }
    }

    return dp[n][m];
  }
};
