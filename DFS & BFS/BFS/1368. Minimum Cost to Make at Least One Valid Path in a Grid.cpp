/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// 0-1 BFS SOLUTION

class Solution
{
private:
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  int minCost(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();

    deque<vector<int>> dq;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    dq.push_back({0, 0, 0});
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = 0;

    while (!dq.empty())
    {
      vector<int> curr = dq.front();
      dq.pop_front();
      int x = curr[1], y = curr[2], cost = curr[0];

      int idx = 0;
      for (vector<int> &d : dir)
      {
        int nx = x + d[0], ny = y + d[1], ncost = cost;

        if (isValid(nx, ny))
        {
          // cout << nx << "   " <<  ny << "   " << cost << endl;
          if (idx != grid[x][y] - 1)
            ncost += 1;

          if (dist[nx][ny] > ncost)
          {
            dist[nx][ny] = ncost;
            if (ncost > cost)
              dq.push_back({ncost, nx, ny});
            else
              dq.push_front({ncost, nx, ny});
          }
        }
        idx++;
      }
    }
    return dist.back().back();
  }
};

// PRIORITY QUEUE SOLUTION
class Solution
{
private:
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  int minCost(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    pq.push({0, 0, 0});

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    while (!pq.empty())
    {
      vector<int> curr = pq.top();
      int x = curr[1], y = curr[2], cost = curr[0];

      int idx = 0;
      for (vector<int> &d : dir)
      {
        int nx = x + d[0], ny = y + d[1], ncost = cost;

        if (isValid(nx, ny))
        {
          if (idx == grid[x][y] - 1)
            ncost += 1;

          if (dist[nx][ny] > ncost)
          {
            dist[nx][ny] = ncost;
            pq.push({ncost, nx, ny});
          }
        }
        idx++;
      }
      pq.pop();
    }
    return dist.back().back();
  }
};