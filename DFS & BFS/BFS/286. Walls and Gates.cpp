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
  const int INF = INT_MAX;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  void wallsAndGates(vector<vector<int>> &rooms)
  {
    queue<vector<int>> q;
    m = rooms.size(), n = rooms[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (rooms[i][j] == 0)
        {
          q.push({i, j, 0});
          visited[i][j] = true;
        }
      }
    }

    while (q.empty() == false)
    {
      vector<int> curr = q.front();
      int i = curr[0], j = curr[1], distance = curr[2];
      q.pop();
      for (vector<int> &d : dir)
      {
        int ni = i + d[0];
        int nj = j + d[1];

        if (isValid(ni, nj) && !visited[ni][nj] && rooms[ni][nj] != -1)
        {
          rooms[ni][nj] = distance + 1;
          q.push({ni, nj, distance + 1});
          visited[ni][nj] = true;
        }
      }
    }
  }
};