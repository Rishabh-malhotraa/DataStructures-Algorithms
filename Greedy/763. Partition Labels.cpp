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
  vector<int> partitionLabels(string S)
  {
    // grredly okay smallest partition which the first alphabhet
    vector<int> result;
    int n = S.size();

    vector<int> map(26, -1);

    for (int i = n - 1; i >= 0; i--)
    {
      int idx = S[i] - 'a';
      if (map[idx] == -1)
        map[idx] = i;
    }

    int len = 0, part = 0;
    for (int i = 0; i < n; i++)
    {
      int idx = S[i] - 'a';
      part = max(part, map[idx]);
      len++;

      if (part == i)
      {
        result.push_back(len);
        len = 0;
      }
    }
    return result;
  }
};