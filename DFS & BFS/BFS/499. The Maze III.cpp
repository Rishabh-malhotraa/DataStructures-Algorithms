/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Cell
{
public:
  int x;
  int y;
};

class Solution
{
private:
  int m, n;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<char> directions = {'r', 'd', 'l', 'u'};

  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole)
  {
    m = maze.size(), n = maze[0].size();

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    vector<vector<string>> path(m, vector<string>(n, "z"));

    queue<Cell> q({{ball[0], ball[1]}});

    dp[ball[0]][ball[1]] = 0;
    path[ball[0]][ball[1]] = "";

    while (!q.empty())
    {
      Cell curr = q.front();
      q.pop();

      int idx = 0;
      for (vector<int> &d : dir)
      {
        int nx = curr.x + d[0], ny = curr.y + d[1], nlen = dp[curr.x][curr.y] + 1;
        string curr_path = path[curr.x][curr.y] + directions[idx++];
        while (isValid(nx, ny) && maze[nx][ny] != 1 && hole != vector<int>{nx, ny})
          nx += d[0], ny += d[1], nlen += 1;

        if (hole != vector<int>{nx, ny})
          nx -= d[0], ny -= d[1], nlen--;

        if (nx == curr.x && ny == curr.y)
        {
          continue;
        }

        // current length is smaller or equal
        if (nlen <= dp[nx][ny])
        {
          if (nlen < dp[nx][ny])
          {
            dp[nx][ny] = nlen;
            path[nx][ny] = curr_path;
          }
          else if (curr_path < path[nx][ny])
            path[nx][ny] = curr_path;

          q.push({nx, ny});
        }
      }
    }
    string result = (path[hole[0]][hole[1]] == "z") ? "impossible" : path[hole[0]][hole[1]];
    return result;
  }
};