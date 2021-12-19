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
  bool dfs(string &s, string word, int idx, unordered_set<string> &cache, vector<int> &dp)
  {
    int n = s.size();

    if (idx == n)
      return true;

    if (dp[idx] != -1)
      return dp[idx];

    // [L- E - E - T]
    for (int i = idx; i < n; i++)
    {
      word.push_back(s[i]); // app

      if (cache.find(word) != cache.end()) // if we find the word in our cache
      {
        bool result = dfs(s, "", i + 1, cache, dp);
        if (result)
        {
          return true;
        }
      }
    }

    return dp[idx] = false;
  }

  bool wordBreak(string s, vector<string> &wordDict)
  {
    unordered_set<string> cache(wordDict.begin(), wordDict.end()); // O(1) lookup time

    vector<int> dp(s.size() + 1, -1);

    // we want to do a dfs call now
    string word = "";
    bool result = dfs(s, word, 0, cache, dp);

    return result;
  }
};