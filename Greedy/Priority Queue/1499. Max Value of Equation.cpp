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
  int findMaxValueOfEquation(vector<vector<int>> &points, int k)
  {
    priority_queue<pair<int, int>> pq;
    pq.push({points[0][1] - points[0][0], points[0][0]});

    int n = points.size();
    int maxValue = INT_MIN;
    for (int i = 1; i < n; i++)
    {
      int x = points[i][0], y = points[i][1];

      while (!pq.empty() && x - pq.top().second > k)
        pq.pop();

      if (pq.empty() == false)
        maxValue = max(maxValue, pq.top().first + x + y);

      pq.push({y - x, x});
    }
    return maxValue;
  }
};