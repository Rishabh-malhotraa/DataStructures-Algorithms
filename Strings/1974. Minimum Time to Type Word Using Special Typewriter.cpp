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
  int minTimeToType(string word)
  {
    int prev = 0, cost = 0;
    for (char ch : word)
    {
      int idx = ch - 'a';

      int dist1 = abs(idx - prev);
      int dist2 = 26 - dist1;
      cost += min(dist1, dist2) + 1;
      prev = idx;
    }
    return cost;
  }
};