/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
class Robot
{
public:
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the current cell.
  bool move();
  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();
  // Clean the current cell.
  void clean();
};

class Solution
{
public:
  vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // cw directions

  set<pair<int, int>> visited;

  void goBack(Robot &robot)
  {
    robot.turnRight();
    robot.turnRight();
    robot.move();
    robot.turnRight();
    robot.turnRight();
  }

  void dfs(Robot &robot, int i, int j, int d)
  {

    visited.insert({i, j});
    robot.clean();

    for (int idx = 0; idx < dir.size(); idx++)
    {
      int nd = (idx + d) % 4;

      int ni = i + dir[nd][0], nj = j + dir[nd][1];

      if (!visited.count({ni, nj}) && robot.move())
      {
        dfs(robot, ni, nj, nd);
        goBack(robot);
      }
      robot.turnRight();
    }
  }

  void cleanRoom(Robot &robot)
  {
    dfs(robot, 0, 0, 0);
  }
};