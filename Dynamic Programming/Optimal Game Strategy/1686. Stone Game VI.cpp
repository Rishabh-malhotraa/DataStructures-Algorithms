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
  int stoneGameVI(vector<int> &A, vector<int> &B)
  {
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    vector<int> stones(2, 0);

    for (int i = 0; i < n; i++)
    {
      dp[i] = {-A[i] - B[i], A[i], B[i]};
    }
    sort(dp.begin(), dp.end());

    for (int i = 0; i < n; i++)
    {
      stones[i % 2] += dp[i][1 + i % 2];
    }
    int result = stones[0] - stones[1];
    return (result == 0) ? 0 : (result > 0) ? 1
                                            : -1;
  }
};
