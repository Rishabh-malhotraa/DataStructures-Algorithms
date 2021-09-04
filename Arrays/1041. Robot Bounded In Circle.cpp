/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// in circle if Δx = 0 or Δdir = 0

class Solution
{
public:
  bool isRobotBounded(string instructions)
  {
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int curr_dir = 0;
    pair<int, int> curr_dist = {0, 0};
    string dir = "URDL";

    for (char &instruction : instructions)
    {
      if (instruction == 'R')
        curr_dir = (curr_dir + 1) % 4;
      else if (instruction == 'L')
        curr_dir = (4 + curr_dir - 1) % 4;
      else
        curr_dist = {curr_dist.first + dir[curr_dir][0], curr_dist.second + dir[curr_dir][1]};
    }

    if (curr_dist == pair<int, int>{0, 0} || curr_dir != 0)
      return true;
    else
      return false;
  }
};