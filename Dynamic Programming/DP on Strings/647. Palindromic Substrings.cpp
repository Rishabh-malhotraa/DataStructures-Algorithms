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
  int countSubstrings(string s)
  {
    int n = s.size(), count = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int gap = 0; gap < n; gap++)
    {
      for (int i = 0, j = gap; j < n; i++, j++)
      {
        if (gap == 0)
        {
          count++;
          dp[i][j] = 1;
        }
        else if (gap == 1)
        {
          if (s[i] == s[j])
          {
            dp[i][j] = 1;
            count++;
          }
        }
        else
        {
          if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
          {
            dp[i][j] = 1;
            count++;
          }
        }
      }
    }

    return count;
  }
};