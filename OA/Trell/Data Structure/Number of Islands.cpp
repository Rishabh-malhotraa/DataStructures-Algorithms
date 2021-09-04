/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class getIsland
{
private:
  int m, n;
  const int VISITED = 2;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  void dfs(int i, int j, vector<vector<int>> &matrix)
  {
    matrix[i][j] = VISITED;

    for (vector<int> &d : dir)
    {
      int ni = i + d[0], nj = j + d[1];
      if (isValid(ni, nj) && matrix[ni][nj] == 1)
        dfs(ni, nj, matrix);
    }
    return;
  }

public:
  int getIslands(vector<vector<int>> &matrix)
  {
    m = matrix.size(), n = matrix[0].size();
    int count = 0;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (matrix[i][j] == 1)
        {
          dfs(i, j, matrix);
          count++;
        }

    return count;
  }
};
