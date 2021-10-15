
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
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
  {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> prefixSum = matrix;
    unordered_map<int, int> cache;
    int result = 0;

    for (int row = 0; row < m; row++)
      for (int col = 1; col < n; col++)
        prefixSum[row][col] += prefixSum[row][col - 1];

    for (int left = 0; left < n; left++)
    {
      for (int right = left; right < n; right++)
      {
        int currSum = 0;
        cache = {{0, 1}};
        for (int i = 0; i < m; i++)
        {
          currSum += prefixSum[i][right] - (left ? prefixSum[i][left - 1] : 0);

          int key = currSum - target;

          result += cache[key];

          cache[currSum]++;
        }
      }
    }
    return result;
  }
};
