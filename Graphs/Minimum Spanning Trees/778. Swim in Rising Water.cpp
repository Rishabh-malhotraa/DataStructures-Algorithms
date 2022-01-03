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
  int swimInWater(vector<vector<int>> &grid)
  {
    int n = grid.size(), ans = max(grid[0][0], grid[n - 1][n - 1]);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1;
    vector<int> dir({-1, 0, 1, 0, -1});
    pq.push({ans, 0, 0});
    while (!pq.empty())
    {
      auto cur = pq.top();
      pq.pop();
      ans = max(ans, cur[0]);
      queue<pair<int, int>> myq;
      myq.push({cur[1], cur[2]});
      while (!myq.empty())
      {
        auto p = myq.front();
        myq.pop();
        if (p.first == n - 1 && p.second == n - 1)
          return ans;

        for (int i = 0; i < 4; ++i)
        {
          int r = p.first + dir[i], c = p.second + dir[i + 1];
          if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0)
          {
            visited[r][c] = 1;
            if (grid[r][c] <= ans)
              myq.push({r, c});
            else
              pq.push({grid[r][c], r, c});
          }
        }
      }
    }

    return -1;
  }
};