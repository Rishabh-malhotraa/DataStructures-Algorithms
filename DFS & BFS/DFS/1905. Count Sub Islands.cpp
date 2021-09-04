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
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  bool dfs(vector<vector<int>> &A, vector<vector<int>> &B, int i, int j)
  {
    B[i][j] = 0;
    bool result = true;

    for (vector<int> &d : dir)
    {
      int ni = i + d[0], nj = j + d[1];
      if (isValid(ni, nj) && B[ni][nj] == 1)
        result = result & dfs(A, B, ni, nj);
    }

    return result & A[i][j];
  }

public:
  int countSubIslands(vector<vector<int>> &A, vector<vector<int>> &B)
  {
    m = A.size(), n = A[0].size();
    int count = 0;

    // how many subislands in B of A
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (B[i][j] == 1 && dfs(A, B, i, j))
          count++;

    return count;
  }
};