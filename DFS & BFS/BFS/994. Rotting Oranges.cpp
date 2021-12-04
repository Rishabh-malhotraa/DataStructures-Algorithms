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
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  pair<int, int> getCount(vector<vector<int>> &grid)
  {
    int rottenOranges = 0, emptySpaces = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 2)
          rottenOranges++;
        else if (grid[i][j] == 0)
          emptySpaces++;

    return {rottenOranges, emptySpaces};
  }

public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    int days = 0;
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 2)
          q.push({i, j, 0});

    while (q.empty() == false)
    {
      auto [i, j, day] = q.front();
      q.pop();

      for (vector<int> &d : dir)
      {
        int ni = i + d[0], nj = j + d[1];
        if (isValid(ni, nj) && grid[ni][nj] == 1)
        {
          grid[ni][nj] = 2;
          q.push({ni, nj, day + 1});
          days = day + 1;
        }
      }
    }

    auto [rottenOranges, emptySpaces] = getCount(grid);

    return (rottenOranges + emptySpaces == m * n) ? days : -1;
  }
};