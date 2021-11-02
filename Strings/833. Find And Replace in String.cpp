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
  string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
  {
    int n = indices.size(), offset = 0;
    int prev = INT_MAX;
    vector<pair<int, int>> idx;
    for (int i = 0; i < n; i++)
      idx.push_back({indices[i], i});

    sort(idx.rbegin(), idx.rend());

    for (int i = 0; i < n; i++)
    {
      int s_idx = idx[i].first;
      int vec_pos = idx[i].second;

      string source = sources[vec_pos];
      string target = targets[vec_pos];

      if (s.substr(s_idx, source.size()) == source)
      {
        offset += target.size() - source.size(); // you would require offset for inserting from front but no offset required if we start inserting from back
        s.erase(s_idx, source.size());
        s.insert(s_idx, target);
      }
    }
    return s;
  }
};