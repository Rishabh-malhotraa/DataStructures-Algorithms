//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Once Flood Fill is done do normal Find Island Algorithm

class Solution
{
public:
  void dfs(int i, int j, vector<vector<int>> &grid)
  {

    if (i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size() || grid[i][j] == 1)
    {
      return;
    }

    grid[i][j] = 1;

    dfs(i - 1, j, grid);
    dfs(i, j - 1, grid);
    dfs(i + 1, j, grid);
    dfs(i, j + 1, grid);
  }
  int closedIsland(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {

      if (grid[i][0] == 0)
      {
        dfs(i, 0, grid);
      }
      if (grid[i][m - 1] == 0)
      {
        dfs(i, m - 1, grid);
      }
    }

    for (int j = 0; j < m; j++)
    {

      if (grid[0][j] == 0)
      {
        dfs(0, j, grid);
      }
      if (grid[n - 1][j] == 0)
      {
        dfs(n - 1, j, grid);
      }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {

        if (grid[i][j] == 0)
        {
          ans += 1;
          dfs(i, j, grid);
        }
      }
      cout << endl;
    }

    return ans;
  }
};