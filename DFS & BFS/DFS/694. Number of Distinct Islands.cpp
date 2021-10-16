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
  vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<char> cdir = {'U', 'R', 'D', 'L'};

  string dfs(int i, int j, vector<vector<int>> &grid)
  {

    string shape;
    grid[i][j] = 0;

    for (int idx = 0; idx < dir.size(); idx++)
    {
      int ni = i + dir[idx][0];
      int nj = j + dir[idx][1];

      if (isValid(ni, nj) && grid[ni][nj] == 1)
      {
        shape += cdir[idx];
        shape += dfs(ni, nj, grid);
        shape += 'b';
      }
    }
    return shape;
  }

public:
  int numDistinctIslands(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    set<string> s;
    int distinctIslands = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          string shape = dfs(i, j, grid);
          if (s.find(shape) == s.end())
            distinctIslands++;
          s.insert(shape);
        }
      }
    }
    return distinctIslands;
  }
};