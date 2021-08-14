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
  int longestValidParentheses(string s)
  {
    s = ")" + s;
    int n = s.size(), result = 0;
    vector<int> dp(n, 0);

    for (int i = 2; i < n; i++)
    {
      char curr = s[i], prev = s[i - 1];
      int offset = dp[i - 1];
      if (curr == ')')
      {
        if (prev == '(')
          dp[i] = 2 + dp[i - 2];
        else if (prev == ')' && s[i - offset - 1] == '(')
        {
          dp[i] = dp[i - 1] + 2 + dp[i - offset - 2];
        }
      }
      else
      {
        dp[i] = 0;
      }
      result = max(result, dp[i]);
    }
    return result;
  }
};