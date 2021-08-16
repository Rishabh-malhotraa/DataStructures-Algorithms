//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int mod = (int)1e9 + 7;

  int dfs(int m, int n, int k, int x, int y, vector<vector<vector<int>>> &memo)
  {

    if (x < 0 || y < 0 || x == m || y == n)
      return 1;

    if (k == 0)
      return 0;

    if (memo[x][y][k] != -1)
      return memo[x][y][k];

    memo[x][y][k] = 0;

    for (vector<int> d : dir)
    {
      int i = x + d[0];
      int j = y + d[1];
      memo[x][y][k] = (memo[x][y][k] + (dfs(m, n, k - 1, i, j, memo) % mod)) % mod;
    }
    return memo[x][y][k];
  }

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
  {
    vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
    return dfs(m, n, maxMove, startRow, startColumn, memo);
  }
};