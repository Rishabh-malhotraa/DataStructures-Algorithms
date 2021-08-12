//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
      return 0;
    if (visited[i][j] == true || grid[i][j] == 0)
      return 0;
    visited[i][j] = true;
    int result = 1;
    for (int k = 0; k < dir.size(); k++)
      result += dfs(grid, visited, i + dir[k][0], j + dir[k][1]);
    return result;
    // return 1 + dfs(grid, visited, i + 1, j + 0)
    //          + dfs(grid, visited, i - 1, j + 0)
    //          + dfs(grid, visited, i + 0, j + 1)
    //          + dfs(grid, visited, i + 0, j - 1);
  }

  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    int result = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 1 && visited[i][j] == false)
          result = max(result, dfs(grid, visited, i, j));
    return result;
  }
};