//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

int prefixSum(vector<int> &arr)
{
  int n = arr.size();

  vector<int> dp(n + 1, 0);

  for (int i = 1; i <= n; i++)
    dp[i] = dp[i - 1] + arr[i - 1];

  // sum of first 4 elements [0, 1, 2, 3, 4]
  for (int i = 0; i < n; i++)
    cout << dp[i + 1];

  // sum between elements

  int i = 3, j = 1; //-> {1 , 2 ,3  4}
  int s = dp[i + 1] - dp[j];
}

int prefixSumII(vector<vector<int>> &matrix)
{
  int n = matrix.size(), m = matrix[0].size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1];
}