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
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  void dfs(int i, int j, vector<vector<int>> &land, vector<vector<bool>> &visited, set<pair<int, int>> &s)
  {
    visited[i][j] = true;
    s.insert({i, j});

    for (vector<int> &d : dir)
    {
      int ni = i + d[0], nj = j + d[1];

      if (isValid(ni, nj) && visited[ni][nj] == false && land[ni][nj] == 1)
        dfs(ni, nj, land, visited, s);
    }
  }

public:
  vector<vector<int>> findFarmland(vector<vector<int>> &land)
  {
    m = land.size(), n = land[0].size();
    vector<vector<int>> result;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    set<pair<int, int>> s;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (visited[i][j] == false && land[i][j] == 1)
        {
          dfs(i, j, land, visited, s);
          int r1 = s.begin()->first, c1 = s.begin()->second;
          int r2 = s.rbegin()->first, c2 = s.rbegin()->second;
          result.push_back({r1, c1, r2, c2});
          s.clear();
        }
      }
    }
    return result;
  }
};