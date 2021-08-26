#include <bits/stdc++.h>
using namespace std;

// DFS
// count the outof bound instances while doing DFS on a conected component

class Solution
{
public:
  vector<vector<int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
      return 1;
    if (visited[i][j] == true)
      return 0;
    visited[i][j] = true;
    int result = 0;
    for (int k = 0; k < dir.size(); k++)
      result += dfs(grid, visited, i + dir[k][0], j + dir[k][1]);
    return result;
  }

  int islandPerimeter(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    int result = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 1)
          result = max(result, dfs(grid, visited, i, j));
    return result;
  }
};
