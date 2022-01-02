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
1. BFS Solution
-> get all neighoburs or Matrix and do a bfs on its neighbors and so ont

*/

#define Matrix vector<vector<int>>
// typedef vector<vector<int>> Matrix;

class Solution
{
public:
  int m, n;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }
  bool isZeroMatrix(Matrix &grid)
  {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 1)
          return false;
    return true;
  }

  vector<Matrix> getNeighbours(Matrix &grid)
  {
    vector<Matrix> neighbours;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        Matrix newGrid = grid;
        newGrid[i][j] = !grid[i][j];

        for (vector<int> &d : dir)
        {
          int ni = i + d[0], nj = j + d[1];
          if (isValid(ni, nj))
            newGrid[ni][nj] = !grid[ni][nj];
        }
        neighbours.push_back(newGrid);
      }
    }
    return neighbours;
  }

  int minFlips(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();

    queue<Matrix> q;

    map<Matrix, int> cache;
    q.push(grid);
    cache[grid] = 0;

    while (!q.empty())
    {
      Matrix currGrid = q.front();
      int steps = cache[currGrid];
      q.pop();
      // cout << "Hello " << steps << endl;
      if (isZeroMatrix(currGrid))
        return steps;

      vector<Matrix> neighbours = getNeighbours(currGrid);

      for (Matrix &neighbour : neighbours)
        if (cache.find(neighbour) == cache.end())
          q.push(neighbour), cache[neighbour] = steps + 1;
    }
    return -1;
  }
};