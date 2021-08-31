/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// BFS with smartness lol | Anything you can do I can do better

class Solution
{
private:
  int n, m;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
  {
    m = maze.size(), n = maze[0].size();
    queue<vector<int>> q({{start[0], start[1], 0}});
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[start[0]][start[1]] = 0;
    while (q.empty() == false)
    {
      vector<int> curr = q.front();
      q.pop();
      int x = curr[0], y = curr[1], len = curr[2];

      // if (dp[x][y] < len)
      //   continue;

      for (vector<int> &d : dir)
      {
        int nx = x + d[0];
        int ny = x + d[1];
        int nlen = len + 1;
        while (isValid(nx, ny) && maze[nx][ny] != 1)
          nx += d[0], ny += d[1], nlen++;

        nx -= d[0], ny -= d[1], nlen--;

        if (dp[nx][ny] > nlen)
        {
          dp[nx][ny] = nlen;
          q.push({nx, ny, nlen});
        }
      }
    }

    return (dp[destination[0]][destination[1]] == INT_MAX) ? -1 : dp[destination[0]][destination[1]];
  }
};