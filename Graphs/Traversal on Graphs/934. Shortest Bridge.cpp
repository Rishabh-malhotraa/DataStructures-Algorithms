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

private:
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<int, int>> &q)
  {
    grid[i][j] = 2;
    q.push({i, j});
    for (vector<int> &d : dir)
    {
      int ni = i + d[0], nj = j + d[1];
      if (isValid(ni, nj) && grid[ni][nj] == 1)
        dfs(ni, nj, grid, q);
    }
  }

public:
  int shortestBridge(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    bool found = false;
    for (int i = 0; i < m && !found; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 1)
        {
          dfs(i, j, grid, q);
          found = true;
          break;
        }

    int steps = 0;
    while (!q.empty())
    {
      int len = q.size();
      for (int i = 0; i < len; i++)
      {
        pair<int, int> curr = q.front();
        q.pop();
        for (vector<int> &d : dir)
        {
          int ni = curr.first + d[0], nj = curr.second + d[1];
          if (isValid(ni, nj) && grid[ni][nj] != 2)
          {
            if (grid[ni][nj] == 1)
              return steps;
            if (grid[ni][nj] == 0)
            {
              grid[ni][nj] = 2;
              q.push({ni, nj});
            }
          }
        }
      }
      steps++;
    }
    cout << steps << endl;
    return -1;
  }
};