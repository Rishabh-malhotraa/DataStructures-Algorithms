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
  vector<int> prefixSum;
  vector<vector<int>> cache;

  void getPrefix(vector<int> &arr)
  {
    int n = arr.size();

    for (int i = 1; i <= n; i++)
      prefixSum[i] = arr[i - 1] + prefixSum[i - 1];
  }

  int dfs(int l, int r)
  {
    if (r - l <= 0)
      return cache[l][r] = 0;

    if (cache[l][r] != -1)
      return cache[l][r];

    int result = INT_MIN, score = 0;

    for (int split = l; split < r; split++)
    {
      int left = prefixSum[split + 1] - prefixSum[l];
      int right = prefixSum[r + 1] - prefixSum[split + 1];

      if (left < right)
        score = left + dfs(l, split);
      else if (left > right)
        score = right + dfs(split + 1, r);
      else
        score = max(left + dfs(l, split), right + dfs(split + 1, r));

      result = max(result, score);
    }

    return cache[l][r] = result;
  }

public:
  int stoneGameV(vector<int> &stoneValue)
  {
    int n = stoneValue.size();
    cache = vector<vector<int>>(n, vector<int>(n, -1));
    prefixSum.assign(n + 1, 0);
    getPrefix(stoneValue);

    return dfs(0, n - 1);
  }
};

// +++++ TABULATION ++++++ //

class Solution
{
public:
  int stoneGameV(vector<int> &stoneValue)
  {
    int n = stoneValue.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prefixSum(n + 1, 0);

    for (int i = 1; i <= n; i++)
      prefixSum[i] = prefixSum[i - 1] + stoneValue[i - 1];
    int left, right;
    for (int gap = 1; gap < n; gap++)
    {
      for (int i = 0, j = gap; j < n; i++, j++)
      {
        for (int k = i; k < j; k++)
        {
          // |  |   ----- |
          //  0, 1, 2, 3, 4
          left = prefixSum[k + 1] - prefixSum[i];
          right = prefixSum[j + 1] - prefixSum[k + 1];

          if (right > left)
          {
            dp[i][j] = max(dp[i][j], left + dp[i][k]);
          }
          else if (left > right)
          {
            dp[i][j] = max(dp[i][j], right + dp[k + 1][j]);
          }
          else
          {
            dp[i][j] = max(dp[i][j], left + max(dp[i][k], dp[k + 1][j]));
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};