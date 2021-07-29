#include <bits/stdc++.h>
using namespace std;

// 200. Number of Islands
// Given that the grid is covered with water

// DFS || Count number of components || Union Find

class Solution
{
private:
  int m, n;
  vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  void dfs(int i, int j, vector<vector<char>> &grid)
  {
    if (isValid(i, j) == false || grid[i][j] == '0')
      return;

    grid[i][j] = '0';
    for (vector<int> &d : dir)
      dfs(d[0] + i, d[1] + j, grid);
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int count = 0;
    m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == '1')
        {
          dfs(i, j, grid);
          count++;
        }
    return count;
  }
};