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
  int minFallingPathSum(vector<vector<int>> &A)
  {

    int n = A.size();

    vector<int> dp(A[0].begin(), A[0].end());

    for (int i = 1; i < n; i++)
    {
      vector<int> newDp(n, INT_MAX);
      for (int j = 0; j < n; j++)
      {
        int left = (j - 1 >= 0) ? dp[j - 1] : INT_MAX;
        int right = (j + 1 < n) ? dp[j + 1] : INT_MAX;
        int mid = dp[j];
        newDp[j] = A[i][j] + min({mid, left, right});
      }
      dp = newDp;
    }
    return *min_element(dp.begin(), dp.end());
  }
};