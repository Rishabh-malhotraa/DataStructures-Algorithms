/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class WordDistance
{
public:
  unordered_map<string, vector<int>> cache;
  WordDistance(vector<string> &words)
  {
    int idx = 0;
    for (string word : words)
      cache[word].push_back(idx++);
  }

  int shortest(string word1, string word2)
  {
    vector<int> a = cache[word1], b = cache[word2];
    int i = 0, j = 0, n = a.size(), m = b.size();
    int diff = INT_MAX;

    while (i < n && j < m)
    {
      diff = min(diff, abs(a[i] - b[j]));
      if (a[i] > b[j])
        j++;
      else
        i++;
    }
    return diff;
  }
};