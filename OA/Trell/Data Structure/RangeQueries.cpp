/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class RangeQuery
{
private:
  vector<vector<int>> prefixSum;
  int m, n;

public:
  void getPrefixSum(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    prefixSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + grid[i - 1][j - 1];
  }

  int getSum(int x1, int y1, int x2, int y2)
  {
    return prefixSum[x2 + 1][y2 + 1] - prefixSum[x2 + 1][y1] - prefixSum[x1][y2 + 1] + prefixSum[x1][y1];
  }

  void rangeQueries(vector<vector<int>> &matrix, vector<vector<int>> &queries)
  {
    getPrefixSum(matrix);
    for (vector<int> &query : queries)
      cout << getSum(query[0], query[1], query[2], query[3]) << endl;
  }
};