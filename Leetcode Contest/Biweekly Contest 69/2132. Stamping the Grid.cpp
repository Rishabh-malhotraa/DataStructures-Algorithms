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
  vector<vector<int>> dp;
  vector<vector<int>> grid;
  vector<vector<bool>> visited;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  int h, w;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  void precomputeSum(vector<vector<int>> &grid)
  {

    int row = grid.size();
    int col = row > 0 ? grid[0].size() : 0;

    dp = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));

    for (int i = 1; i <= row; i++)
      for (int j = 1; j <= col; j++)
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i - 1][j - 1];
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    // just look at the example you'll understand the offsets
  }

  bool canFill(int i, int j)
  {
    vector<tuple<int, int, int, int>> neighbours = {
        {i - h, j - w, i, j},
        {i, j, i + h, j + w},
        {i - h, j, i, j + w},
        {i, j - h, i + h, j},
    };

    for (auto [x1, y1, x2, y2] : neighbours)
      if (isValid(x1, y1) && isValid(x2, y2) && sumRegion(x1, y1, x2, y2) == 0)
        return true;
    return false;
  }

  void bfs(int x, int y)
  {
    queue<pair<int, int>> q;
    q.push({x, y});

    // for(int i = x; i <= x + h; i++)
    //   for(int j = y; j<= y + w; j++)
    //     visited[i][j] = true;

    while (q.empty() == false)
    {
      auto [i, j] = q.front();
      q.pop();

      for (auto d : dir)
      {
        int ni = i + d[0];
        int nj = j + d[1];

        if (isValid(ni, nj) && grid[ni][nj] == 1 && visited[ni][nj] == false && canFill(ni, nj))
        {
          visited[ni][nj] = true;
          q.push({ni, nj});
        }
      }
    }
  }

public:
  bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth)
  {
    m = grid.size(), n = grid[0].size();
    this->h = stampHeight - 1;
    this->w = stampWidth - 1;
    this->grid = grid;
    this->visited = vector<vector<bool>>(m, vector<bool>(n, 0));
    precomputeSum(grid);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (visited[i][j] == false && canFill(i, j))
        {
          visited[i][j] = true;
          bfs(i, j);
        }
      }
    }

    int count = 0, location = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << visited[i][j] << " ";
        if (grid[i][j] == 0)
        {
          location++;
          if (visited[i][j] == true)
            count++;
        }
      }
      cout << endl;
    }
    cout << count << " " << location << endl;
    return location == count;
  }
};