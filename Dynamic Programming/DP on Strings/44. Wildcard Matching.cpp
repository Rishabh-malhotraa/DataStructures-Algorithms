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
  bool isMatch(string s, string p)
  {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    //   s t r i n g _
    // p
    // a
    // t
    // t
    // e
    // r
    // n
    // _

    dp[m][n] = true;
    for (int i = m - 1; i >= 0; i--)
    {
      for (int j = n; j >= 0; j--)
      {
        if (j == n)
          dp[i][j] = (p[i] == '*') ? dp[i + 1][j] : false;
        else
        {
          char ch = p[i];
          if (ch == '*')
            dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
          else if (ch == '?')
            dp[i][j] = dp[i + 1][j + 1];
          else
            dp[i][j] = (ch == s[j]) ? (dp[i + 1][j + 1]) : false;
        }
      }
    }
    return dp[0][0];
  }
};