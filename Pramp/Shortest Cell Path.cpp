/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int m, n;

bool isValid(int i, int j)
{
  return (i >= 0 && i < m && j >= 0 && j < n);
}

int shortestCellPath(const vector<vector<int>> &grid_, int sr, int sc, int tr, int tc)
{
  vector<vector<int>> grid = grid_;
  m = grid.size(), n = grid[0].size();

  queue<vector<int>> q;

  q.push({sr, sc, 0});

  while (q.empty() == false)
  {
    vector<int> curr = q.front();

    int i = curr[0], j = curr[1], distance = curr[2];
    q.pop();

    grid[i][j] = 0; // cell i,j is visited

    if (i == tr && j == tc)
      return distance;

    for (vector<int> &d : dir)
    {
      int ni = i + d[0];
      int nj = j + d[1];

      if (isValid(ni, nj) && grid[ni][nj] == 1)
        q.push({ni, nj, distance + 1});
    }
  }

  return -1;
}

/*

TC: O(V+E) => O(m*n + 4*m*n) => O(m*n)


X
1 1 1 1
0 - - -
1 1 1 1
Y
        T
     1  0
     1  0
   1 S(0,0,)  1
     1



 queue -> [coord, distance]



 [(0,0),   0]
 [(-1,0) , 1]
 [ ]

*/