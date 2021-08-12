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
  // Input: s = "aaabcccd", k = 2 :: answer -> 4
  int chainLength(int x)
  {
    if (x == 1)
    {
      return 1;
    }
    else if (x < 10)
    {
      return 2;
    }
    else if (x < 100)
    {
      return 3;
    }
    else
    {
      return 4;
    }
  }

  int getLengthOfOptimalCompression(string s, int k)
  {
    // you need to find the length

    int n = s.size();
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= k; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        dp[i][j] = INT_MAX;
        if (i > 0)
          dp[i][j] = dp[i - 1][j - 1];
        int count = 0, removed = 0;
        for (int idx = j; idx > 0; idx--)
        {
          if (s[idx - 1] == s[j - 1])
            count++;
          else if (++removed > i)
            break;
          dp[i][j] = min(dp[i][j], chainLength(count) + dp[i - removed][idx - 1]);
        }
      }
    }
    return dp[k][n];
  }
};