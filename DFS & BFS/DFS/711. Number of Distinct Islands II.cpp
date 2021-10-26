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
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  void dfs(int i, int j, vector<vector<int>> &grid, vector<pair<int, int>> &path)
  {
    grid[i][j] = 0;
    path.push_back({i, j});

    for (vector<int> &d : dir)
    {
      int ni = i + d[0], nj = j + d[1];

      if (isValid(ni, nj) && grid[ni][nj] == 1)
        dfs(ni, nj, grid, path);
    }
  }

  vector<pair<int, int>> normalise(vector<pair<int, int>> shape)
  {
    vector<vector<pair<int, int>>> shapes(8);

    for (auto [x, y] : shape)
    {
      shapes[0].push_back({x, y});
      shapes[1].push_back({-x, y});
      shapes[2].push_back({x, -y});
      shapes[3].push_back({-x, -y});
      shapes[4].push_back({y, x});
      shapes[5].push_back({y, -x});
      shapes[6].push_back({-y, x});
      shapes[7].push_back({-y, -x});
    }

    // making smallest element x as origin
    for (vector<pair<int, int>> &shape_ : shapes)
    {
      // sorting is very imporant for last comparison
      sort(shape_.begin(), shape_.end());

      auto [origin_x, origin_y] = shape_.front();

      for (auto &[x, y] : shape_)
      {
        x -= origin_x;
        y -= origin_y;
      }
    }
    return *min_element(shapes.begin(), shapes.end());
  }

public:
  int numDistinctIslands2(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    set<vector<pair<int, int>>> shapes;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          vector<pair<int, int>> shape;
          dfs(i, j, grid, shape);
          shapes.insert(normalise(shape));
        }
      }
    }
    return shapes.size();
  }
};
