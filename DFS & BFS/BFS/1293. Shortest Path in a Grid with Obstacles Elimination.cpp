/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// you have k lives, you can revisit a cell only if you improve the number of lives in that cell
// HARD

// nodes which are faster will reach a given cell by breaking more wall but they might get stuck ahead
// so therefore we need to aso process the nodes which would visit the same cell but with having less livs

class Solution
{
private:
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  int shortestPath(vector<vector<int>> &grid, int k)
  {
    m = grid.size(), n = grid[0].size();
    // x - y - length - lives
    queue<vector<int>> q({{0, 0, 0, k}});
    vector<vector<int>> visited(m, vector<int>(n, -1));

    while (q.empty() == false)
    {
      vector<int> curr = q.front();
      int i = curr[0], j = curr[1], distance = curr[2], lives = curr[3];
      q.pop();

      // destination
      if (i == m - 1 && j == n - 1)
        return distance;

      // current cell is a wall
      if (grid[i][j] == 1)
        if (lives > 0)
          lives--;
        else
          continue;

      // relaxation if current ceel could be reached in more lives
      if (visited[i][j] != -1 && visited[i][j] >= lives)
        continue;

      visited[i][j] = lives;

      // 4 directions
      for (vector<int> &d : dir)
      {
        int x = i + d[0];
        int y = j + d[1];

        if (isValid(x, y))
          q.push({x, y, distance + 1, lives});
      }
    }
    return -1;
  }
};
