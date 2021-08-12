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
  int maxEnvelopes(vector<vector<int>> &A)
  {
    int n = A.size(), result = 0;

    vector<int> dp(n, 1);

    sort(A.begin(), A.end(), [](vector<int> x, vector<int> y)
         { return x[0] < y[0]; });

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (A[i][1] > A[j][1] && A[i][0] > A[j][0])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      result = max(result, dp[i]);
    }
    return result;
  }
};