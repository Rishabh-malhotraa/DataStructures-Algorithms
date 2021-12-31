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
  int minAreaRect(vector<vector<int>> &points)
  {
    set<vector<int>> cache;
    int n = points.size();
    for (vector<int> &point : points)
      cache.insert(point);
    int minArea = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int x1 = points[i][0], x2 = points[j][0];
        int y1 = points[i][1], y2 = points[j][1];

        if (x1 != x2 && y1 != y2)
          if (cache.count({x1, y2}) && cache.count({x2, y1}))
            minArea = min(minArea, abs(x1 - x2) * abs(y1 - y2));
      }
    }
    return minArea == INT_MAX ? 0 : minArea;
  }
};