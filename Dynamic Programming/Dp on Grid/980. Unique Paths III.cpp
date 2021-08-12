//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int m, n, cells_to_visit = 0;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  int dfs(pair<int, int> curr, pair<int, int> destination, int visited, vector<vector<int>> &grid)
  {
    int i = curr.first, j = curr.second;
    if (curr == destination)
      return visited == cells_to_visit ? 1 : 0;

    int sum = 0;

    grid[i][j] = -1;
    for (vector<int> &d : dir)
    {
      int x = i + d[0];
      int y = j + d[1];
      if (isValid(x, y) && grid[x][y] != -1)
        sum += dfs({x, y}, destination, visited + 1, grid);
    }
    grid[i][j] = 0;

    return sum;
  }

public:
  int uniquePathsIII(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    pair<int, int> start, end;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] != -1)
          cells_to_visit++;
        if (grid[i][j] == 1)
          start = {i, j};
        if (grid[i][j] == 2)
          end = {i, j};
      }
    }
    return dfs(start, end, 1, grid);
  }
};