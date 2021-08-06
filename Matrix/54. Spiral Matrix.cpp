//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Simulation | Layer by Layer | 0_0

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
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result;
    int currDir = 0;
    int x = 0;
    int y = 0;
    while (result.size() < m * n)
    {
      if (matrix[x][y] != INT_MIN)
      {
        result.push_back(matrix[x][y]);
        matrix[x][y] = INT_MIN;
      }

      vector<int> d = dir[currDir % 4];

      int nx = x + d[0];
      int ny = y + d[1];

      if (isValid(nx, ny) && matrix[nx][ny] != INT_MIN)
        x = nx, y = ny;
      else
        currDir++;
    }
    return result;
  }
};