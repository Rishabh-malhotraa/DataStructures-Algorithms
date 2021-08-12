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
  bool wordBreak(string s, vector<string> &wordDict)
  {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    unordered_set<string> keys(wordDict.begin(), wordDict.end());

    dp[0] = true;
    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 0; j < i; j++)
      {
        string curr = s.substr(j, i - j);

        if (dp[j] && keys.count(curr))
          dp[i] = true;

        if (dp[i])
          break;
      }
    }

    return dp[n];
  }
};