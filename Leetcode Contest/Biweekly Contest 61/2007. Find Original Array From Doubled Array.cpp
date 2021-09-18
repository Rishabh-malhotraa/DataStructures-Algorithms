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
  vector<int> findOriginalArray(vector<int> &changed)
  {
    if (changed.size() == 1)
      return {};

    int n = changed.size();
    unordered_map<int, int> freq;
    sort(changed.begin(), changed.end());
    vector<int> result;

    for (int &el : changed)
      freq[el]++;

    for (int i = 0; i < n; i++)
    {
      int el = changed[i];

      if (freq[el] == 0)
        continue;

      freq[el]--;

      if (freq.find(el * 2) != freq.end() && freq[el * 2] > 0)
      {
        result.push_back(el);
        freq[el * 2]--;
      }
      else
        return {};
    }
    return result;
  }
};