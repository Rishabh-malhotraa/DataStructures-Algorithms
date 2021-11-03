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
  int m, n;
  const int WALL = 1;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  vector<vector<int>> findFarthestRooms(vector<vector<int>> &grid, int x, int y)
  {
    m = grid.size(), n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    vector<vector<int>> rooms;
    int farthestRoom = 0;

    while (q.empty() == false)
    {
      auto [i, j, distance] = q.front();

      if (distance >= farthestRoom)
      {
        if (distance == farthestRoom)
          rooms.push_back({i, j});
        else
        {
          // we have a new room which is the farther
          // flush previous result
          rooms.clear();
          rooms.push_back({i, j});
        }
      }

      for (vector<int> &d : dir)
      {
        int ni = i + d[0];
        int nj = j + d[1];

        if (isValid(ni, nj) && visited[ni][nj] == false && grid[i][j] != WALL)
          q.push({ni, nj, distance + 1});
      }
    }
    return rooms;
  }
};