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
  int shortestPathLength(vector<vector<int>> &graph)
  {
    queue<tuple<int, int, int>> q;
    int n = graph.size();
    set<pair<int, int>> visited;
    for (int i = 0; i < n; i++)
    {
      q.push({i, 1 << i, 0});
      visited.insert({i, 1 << i});
    }

    while (q.empty() == false)
    {
      auto [node, mask, path] = q.front();
      q.pop();

      if (mask == (1 << n) - 1)
        return path;

      for (int neighbour : graph[node])
      {
        int newMask = mask | (1 << neighbour);

        if (!visited.count({neighbour, newMask}))
        {
          q.push({neighbour, newMask, path + 1});
          visited.insert({neighbour, newMask});
        }
      }
    }
    return -1;
    }
};