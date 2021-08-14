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
  int checkSize(int x, int y, int k, vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    if ((x + k >= n) || (y + k >= m))
      return 1;

    // diagonal left -> right

    long long d1 = 0, d2 = 0;
    for (int z = 0; z <= k; z++)
      d1 += grid[x + z][y + z];

    for (int z = 0; z <= k; z++)
      d2 += grid[x + k - z][y + z];

    if (d1 != d2)
      return 1;

    long long sum = 0;
    for (int i = x; i <= x + k; i++)
    {
      sum = 0;
      for (int j = y; j <= y + k; j++)
        sum += grid[i][j];
      if (sum != d1)
        return 1;
    }
    for (int i = y; i <= y + k; i++)
    {
      sum = 0;
      for (int j = x; j <= x + k; j++)
      {
        sum += grid[j][i];
      }
      if (sum != d1)
        return 1;
    }
    return k + 1;
  }

  int largestMagicSquare(vector<vector<int>> &grid)
  {
    int result = 1;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int k = 0; k < min(n, m); k++)
          result = max(result, checkSize(i, j, k, grid));

    return result;
  }
};