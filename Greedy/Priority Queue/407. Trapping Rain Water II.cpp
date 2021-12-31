/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  int trapRainWater(vector<vector<int>> &heightMap)
  {
    m = heightMap.size(), n = heightMap[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // add boundry elements

    for (int j = 0; j < n; j++)
    {
      pq.push({heightMap[0][j], {0, j}});
      pq.push({heightMap[m - 1][j], {m - 1, j}});
      visited[0][j] = visited[m - 1][j] = true;
    }

    for (int i = 1; i < m - 1; i++)
    {
      pq.push({heightMap[i][0], {i, 0}});
      pq.push({heightMap[i][n - 1], {i, n - 1}});
      visited[i][0] = visited[i][n - 1] = true;
    }

    int rainWater = 0;
    int maxHeight = INT_MIN;
    while (pq.empty() == false)
    {
      auto [height, coord] = pq.top();
      auto [i, j] = coord;
      maxHeight = max(maxHeight, height);
      rainWater += maxHeight - height;
      pq.pop();

      for (vector<int> d : dir)
      {
        int ni = i + d[0], nj = j + d[1];

        if (isValid(ni, nj) && visited[ni][nj] == false)
        {
          visited[ni][nj] = true;
          pq.push({heightMap[ni][nj], {ni, nj}});
        }
      }
    }
    return rainWater;
  }
};