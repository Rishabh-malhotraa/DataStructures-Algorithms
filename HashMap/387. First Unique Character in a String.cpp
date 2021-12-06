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
  int firstUniqChar(string s)
  {
    unordered_map<char, pair<int, int>> cache;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
      char ch = s[i];
      if (cache.find(ch) == cache.end())
        cache.insert({ch, {i, 1}});
      else
        cache[ch].second++;
    }
    int idx = INT_MAX;
    for (auto [character, freq] : cache)
    {
      if (freq.second == 1)
        idx = min(idx, freq.first);
    }
    return (idx == INT_MAX) ? -1 : idx;
  }
};