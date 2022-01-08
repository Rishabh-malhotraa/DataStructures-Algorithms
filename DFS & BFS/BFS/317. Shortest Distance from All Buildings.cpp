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
Things to be mindful of

1. the give block should be reachable by all the buildings
2. The Manhattan distance formaula |p1.x - p2.x| + |p1.y - p2.y| would fail if there is
   an obstance in the path of the Manhattan Distance

  1 - - - - | 0 -  In this case min distance formula would fail
  - - - - - | - -  So you need to do BFS way of finding the shortest path ^^
  - - - - - | - -
  - - - - - | - -
  - - - - - - - -

*/

class Solution
{
  vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }
  void exploreGrid(int origin_i, int origin_j, vector<vector<int>> &visited, vector<vector<pair<int, int>>> &distance)
  {
    queue<tuple<int, int, int>> q({{origin_i, origin_j, 0}});

    visited[origin_i][origin_j] = 2;

    while (q.empty() == false)
    {
      auto [i, j, steps] = q.front();
      q.pop();
      distance[i][j].first += steps;
      distance[i][j].second++;

      for (auto &[di, dj] : dir)
      {
        int ni = i + di;
        int nj = j + dj;
        if (isValid(ni, nj) && visited[ni][nj] == 0)
        {
          visited[ni][nj] = 2;
          q.push({ni, nj, steps + 1});
        }
      }
    }
  }

public:
  int shortestDistance(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    vector<vector<pair<int, int>>> distance(m, vector<pair<int, int>>(n, {0, 0}));
    vector<vector<int>> visited;

    int buildings = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          buildings++;
          visited = grid;
          exploreGrid(i, j, visited, distance);
        }
      }
    }
    int minDistance = INT_MAX;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 0 && distance[i][j].second == buildings)
          minDistance = min(minDistance, distance[i][j].first);

    return minDistance == INT_MAX ? -1 : minDistance;
  }
};
