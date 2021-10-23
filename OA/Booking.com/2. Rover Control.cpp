/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

/*
Given a list of instruction tell the coordinates of the final cell|
PROVIDED : you cant go out of bounds
*/

#include <bits/stdc++.h>
using namespace std;

int n;

bool isValid(int i, int j)
{
  return (i >= 0 && i < n && j >= 0 && j < n);
}

unordered_map<string, pair<int, int>> dir = {
    {"DOWN", {1, 0}},
    {"RIGHT", {0, 1}},
    {"UP", {-1, 0}},
    {"LEFT", {0, -1}},
};

int roverMove(int matrixSize, vector<string> cmds)
{
  n = matrixSize;

  pair<int, int> coord = {0, 0};

  for (string cmd : cmds)
  {

    pair<int, int> d = dir[cmd];
    int ni = coord.first + d.first;
    int nj = coord.second + d.second;
    if (isValid(ni, nj))
    {
      coord = make_pair(ni, nj);
    }
  }
  // cout << coord.first << " " << coord.second << endl;

  int value = (coord.first * n) + coord.second;
  return value;
}