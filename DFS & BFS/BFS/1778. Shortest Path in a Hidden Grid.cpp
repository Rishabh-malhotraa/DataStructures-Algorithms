/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// This is the GridMaster's API interface.
// You should not implement it, or speculate about its implementation
class GridMaster
{
public:
  bool canMove(char direction);
  void move(char direction);
  bool isTarget();
};

class Solution
{
private:
  int startX = 500, startY = 500;
  vector<vector<int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
  vector<char> cdir = {'L', 'D', 'R', 'U'};
  vector<vector<int>> grid;
  int m = 1000, n = 1000;
  void buildGraph(GridMaster &master, int i, int j)
  {
    if (grid[i][j] != 3)
      return;

    if (master.isTarget())
      grid[i][j] = 2;
    else
      grid[i][j] = 1;

    int idx = 0;
    for (vector<int> &d : dirs)
    {
      int ni = i + d[0], nj = j + d[1];
      char dir = cdir[idx], op_dir = cdir[(idx + 2) % 4];

      if (master.canMove(dir) == false)
        grid[ni][nj] = 0;
      else
      {
        master.move(dir);
        buildGraph(master, ni, nj);
        master.move(op_dir);
      }
      idx++;
    }
  }

  int distance()
  {
    queue<vector<int>> q;
    q.push({startX, startY, 0});

    while (!q.empty())
    {
      vector<int> curr = q.front();
      int i = curr[0], j = curr[1], steps = curr[2];
      q.pop();

      if (grid[i][j] == 2)
        return steps;

      for (vector<int> &d : dirs)
      {
        int ni = i + d[0];
        int nj = j + d[1];

        if (grid[ni][nj] == 2)
          return steps + 1;
        if (grid[ni][nj] == 1)
        {
          grid[ni][nj] = 3; //visited;
          q.push({ni, nj, steps + 1});
        }
      }
    }
    return -1;
  }

public:
  int findShortestPath(GridMaster &master)
  {
    grid = vector<vector<int>>(m, vector<int>(n, 3));
    buildGraph(master, startX, startY);

    return distance();
  }
};

class Solution
{
private:
  int startX = 500, startY = 500;
  vector<vector<int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
  vector<char> cdir = {'L', 'D', 'R', 'U'};
  vector<vector<int>> grid;
  int m = 1000, n = 1000;
  void buildGraph(GridMaster &master, int i, int j)
  {
    if (grid[i][j] != 3)
      return;

    if (master.isTarget())
      grid[i][j] = 2;

    else
      grid[i][j] = 1;

    int idx = 0;
    for (vector<int> &d : dirs)
    {
      int ni = i + d[0], nj = j + d[1];
      char dir = cdir[idx], op_dir = cdir[(idx + 2) % 4];

      if (master.canMove(dir))
        grid[ni][nj] = 0;
      else
      {
        master.move(dir);
        buildGraph(master, ni, nj);
        master.move(op_dir);
      }
      idx++;
    }
  }

  int distance()
  {
    queue<vector<int>> q;
    q.push({startX, startY, 0});

    while (!q.empty())
    {
      vector<int> curr = q.front();
      int i = curr[0], j = curr[1], steps = curr[2];

      if (grid[i][j] == 2)
        return steps;

      for (vector<int> &d : dirs)
      {
        int ni = i + d[0];
        int nj = j + d[1];

        if (grid[ni][nj] == 1)
        {
          q.push({ni, nj, steps + 1});
          grid[ni][nj] = 0;
        }
      }
    }
    return -1;
  }

public:
  int findShortestPath(GridMaster &master)
  {
    grid = vector<vector<int>>(m, vector<int>(n, 3));
    buildGraph(master, startX, startY);

    return distance();
  }
};