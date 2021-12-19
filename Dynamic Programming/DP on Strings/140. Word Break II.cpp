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
private: // DFS path build function
  void buildPath(bool isBreakable[], string &s, int pos, vector<string> &res, string curP, unordered_set<string> &wordDict, int minlen, int maxlen)
  {
    int i, len = s.size();
    for (i = minlen; i <= min(maxlen, len - pos); ++i)
      if (isBreakable[pos + i] && wordDict.count(s.substr(pos, i)))
        if (pos + i == len)
          res.push_back(curP + s.substr(pos, i));
        else
          buildPath(isBreakable, s, pos + i, res, curP + s.substr(pos, i) + " ", wordDict, minlen, maxlen);
  }

public:
  vector<string> wordBreak(string s, unordered_set<string> &wordDict)
  {
    int sSize = s.size(), len, i, minlen = INT_MAX, maxlen = INT_MIN;
    vector<string> res;
    bool isBreakable[sSize + 1];
    fill_n(isBreakable, sSize + 1, false);

    for (string word : wordDict)
    { // find the minimum and maximum word length
      minlen = min(minlen, (int)word.length());
      maxlen = max(maxlen, (int)word.length());
    }
    // DP to build isBreakable
    for (i = sSize - minlen, isBreakable[sSize] = true; i >= 0; --i)
      for (len = minlen; len <= min(maxlen, sSize - i); ++len)
      {
        if (isBreakable[i + len] && wordDict.count(s.substr(i, len)))
        {
          isBreakable[i] = true;
          break;
        }
      }
    // if breakable, do DFS path building
    if (isBreakable[0])
      buildPath(isBreakable, s, 0, res, "", wordDict, minlen, maxlen);
    return res;
  }
};