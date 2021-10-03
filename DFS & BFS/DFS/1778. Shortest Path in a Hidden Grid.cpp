/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

// This is the GridMaster's API interface.
// You should not implement it, or speculate about its implementation
class GridMaster
{
public:
  bool canMove(char direction);
  void move(char direction);
  bool isTarget();
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int startX = 500, startY = 500;
  int m = 1000, n = 1000;
  vector<vector<int>> grid;
  const vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  const vector<char> cdir = {'U', 'L', 'D', 'R'};

  void buildGraph(GridMaster &master, int i, int j)
  {
    if (grid[i][j] != 3)
      return;
    if (master.isTarget())
      grid[i][j] = 2;
    else
      grid[i][j] = 1;

    for (int idx = 0; idx < dirs.size(); idx++)
    {
      int ni = i + dirs[idx][0], nj = j + dirs[idx][1];
      char dir = cdir[idx], op_dir = cdir[((idx + 2) % 2)];

      if (!master.canMove(dir))
        grid[i][j] = 0;
      else
      {
        master.move(dir);
        buildGraph(master, ni, nj);
        master.move(op_dir);
      }
    }
  }

public:
  int findShortestPath(GridMaster &master)
  {
    grid = vector<vector<int>>(m, vector<int>(n, 3));

    buildGraph(master, startX, startY);
  }
};