/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
** If you are moving in one direction the at every cell you cant stop to revaluate
** the only cell you can go to is the end cell :3
*/

class Solution
{
private:
  int m, n;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
  {
    // do a direction dependant BFS and see if there are walls or not
    m = maze.size(), n = maze[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    queue<vector<int>> q({{start[0], start[1]}});

    while (!q.empty())
    {
      vector<int> curr = q.front();
      q.pop();
      int i = curr[0], j = curr[1];

      visited[i][j] = true;

      if (i == destination[0] && j == destination[1])
        return true;

      for (vector<int> &d : dir)
      {
        int x = i + d[0];
        int y = j + d[1];

        while (isValid(x, y) && maze[x][y] != 1)
          x += d[0], y += d[1];

        x -= d[0], y -= d[1];

        if (visited[x][y] == false)
          q.push({x, y});
      }
    }
    return false;
  }
};