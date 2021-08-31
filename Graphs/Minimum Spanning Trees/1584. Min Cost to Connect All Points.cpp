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
  int minCostConnectPoints(vector<vector<int>> &points)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = points.size();
    pq.push({0, 0});
    int nodes = 0;
    vector<bool> visited(n, false);
    int result = 0;

    while (nodes++ < n)
    {
      while (!pq.empty() && visited[pq.top().second])
        pq.pop();

      int idx = pq.top().second, wt = pq.top().first;
      visited[idx] = true;
      pq.pop();

      for (int i = 0; i < n; i++)
        if (visited[i] == false)
          pq.push({abs(points[i][0] - points[idx][0]) + abs(points[i][1] - points[idx][1]), i});

      result += wt;
    }

    return result;
  }
};
