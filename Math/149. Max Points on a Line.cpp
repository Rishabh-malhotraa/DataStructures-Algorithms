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
  int maxPoints(vector<vector<int>> &points)
  {

    int n = points.size(), maxPoints = 0;
    for (int i = 0; i < n; i++)
    {
      unordered_map<string, int> cache;
      int same_point = 0;
      for (int j = i; j < n; j++)
      {
        if (points[i] == points[j])
          same_point++;

        int dy = points[j][1] - points[i][1];
        int dx = points[j][0] - points[i][0];
        int gcd = __gcd(dy, dx);

        dy /= gcd, dx /= gcd;

        string key = to_string(dy) + "-" + to_string(dx);

        cache[key]++;
      }

      for (auto [key, count] : cache)
        maxPoints = max(maxPoints, count + same_point);
    }

    return maxPoints;
  }
};