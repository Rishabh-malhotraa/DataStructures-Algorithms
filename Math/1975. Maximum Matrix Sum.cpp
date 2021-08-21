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
  long long maxMatrixSum(vector<vector<int>> &matrix)
  {
    long long minimum = INT_MAX;
    long long n = matrix.size();
    long long count = 0;
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
      for (long long j = 0; j < n; j++)
      {
        long long el = matrix[i][j];
        sum += abs(el);
        minimum = min(abs(el), minimum);

        if (el < 0)
          count++;
      }
    }
    // cout << minimum << " " << sum << endl;
    return ((count & 1) ? (sum - 2 * minimum) : sum);
  }
};