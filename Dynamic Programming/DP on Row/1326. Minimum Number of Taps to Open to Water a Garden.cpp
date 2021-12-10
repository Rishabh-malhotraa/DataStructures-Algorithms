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
  int minTaps(int n, vector<int> &ranges)
  {
    vector<int> garden(n + 1, 1);

    int idx = 0;
    for (int range : ranges)
    {
      int left = max(0, idx - range);
      int right = min(n, idx + range);

      garden[left] = max(garden[left], right - left);
    }
    //       X-------->
    // X--------->
    // 1 2 3 4 5
    int currFarthest = 0, currEnd = 0, steps = 0;
    for (int i = 0; i < garden.size(); i++)
    {
      if (currFarthest == n)
        return steps;
      currFarthest = max(currFarthest, i + garden[i]);
      if (i == currEnd)
      {
        steps++;
        currEnd = currFarthest;
      }
    }
    return -1;
  }
};