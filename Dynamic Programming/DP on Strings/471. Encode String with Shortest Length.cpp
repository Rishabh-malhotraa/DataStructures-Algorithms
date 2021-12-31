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
private:
  string collapse(vector<vector<string>> &dp, string &s, int i, int j)
  {
    string s2 = s + s;
    s2 = s2.substr(1, s2.size() - 2);

    int pos = (s2).find(s);
    string encodedString;
    if (pos != string::npos)
      encodedString = s;
    else
      encodedString = to_string(s.size() / pos) + '[' + dp[i][i + pos - 1] + ']';

    return (encodedString.size() < dp[i][j].size()) ? encodedString : dp[i][j];
  }

public:
  string encode(string s)
  {
    int n = s.size();
    vector<vector<string>> dp(n, vector<string>(n, ""));

    for (int gap = 0; gap < n; gap++)
    {
      for (int i = 0, j = gap; j < n; i++, j++)
      {
        string substring = s.substr(i, j);
        dp[i][j] = substring;
        for (int k = i; k < j; k++)
        {
          string left = dp[i][k];
          string right = dp[k + 1][j];

          if (left.size() + right.size() < dp[i][j].size())
            dp[i][j] = left + right;
        }

        dp[i][j] = collapse(dp, substring, i, j);
      }
    }
    return dp[0][n - 1];
  }
};