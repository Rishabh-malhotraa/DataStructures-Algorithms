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
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  void dfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &visited)
  {
    visited[i][j] = true;

    for (vector<int> &d : dir)
    {
      int x = i + d[0], y = j + d[1];

      if (isValid(x, y) && visited[x][y] == false && heights[x][y] >= heights[i][j])
        dfs(x, y, heights, visited);
    }
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    m = heights.size(), n = heights[0].size();
    vector<vector<bool>> atlantic(m, vector<bool>(n, false)), pacific(m, vector<bool>(n, false));
    vector<vector<int>> result;

    for (int i = 0; i < m; i++)
    {
      dfs(i, 0, heights, pacific);
      dfs(i, n - 1, heights, atlantic);
    }

    for (int i = 0; i < n; i++)
    {
      dfs(0, i, heights, pacific);
      dfs(m - 1, i, heights, atlantic);
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (atlantic[i][j] && pacific[i][j])
          result.push_back({i, j});
      }
    }
    return result;
  }
};