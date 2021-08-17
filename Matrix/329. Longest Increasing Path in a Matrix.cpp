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
  vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

  bool isValidCoordinates(int x, int y)
  {
    return ((x >= m || x < 0 || y >= n || y < 0) ? false : true);
  }

  int dfs(int x, int y, vector<vector<int>> &dp, vector<vector<int>> &matrix)
  {

    if (dp[x][y] != 0)
      return dp[x][y];

    for (vector<int> &d : dir)
    {
      int nx = d[0] + x;
      int ny = d[1] + y;

      if (isValidCoordinates(nx, ny) && matrix[nx][ny] > matrix[x][y])
        dp[x][y] = max(dp[x][y], 1 + dfs(nx, ny, dp, matrix));
    }

    dp[x][y] = dp[x][y] == 0 ? 1 : dp[x][y];
    // cout  << "dp[" << x << "][" <<  y << "] -->" << dp[x][y] << endl;
    return dp[x][y];
  }

public:
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int result = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        result = max(result, dfs(i, j, dp, matrix));

    return result;
  }
};