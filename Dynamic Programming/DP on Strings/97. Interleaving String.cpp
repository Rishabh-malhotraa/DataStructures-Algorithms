//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// DFS on the strings!

class Solution
{
public:
  bool dfs(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp)
  {
    bool result = false;

    if (dp[i][j] != -1)
      return dp[i][j];

    if (i == s1.size() && j == s2.size())
      return true;

    if (s1[i] != s3[i + j] && s2[j] != s3[i + j])
      return false;

    if (i != s1.size() && s1[i] == s3[i + j])
      result = result || dfs(i + 1, j, s1, s2, s3, dp);
    if (j != s2.size() && s2[j] == s3[i + j])
      result = result || dfs(i, j + 1, s1, s2, s3, dp);

    return dp[i][j] = result;
  }

  bool isInterleave(string s1, string s2, string s3)
  {
    int n = s1.size(), m = s2.size();
    if (s1.size() + s2.size() != s3.size())
      return false;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return dfs(0, 0, s1, s2, s3, dp);
  }
};