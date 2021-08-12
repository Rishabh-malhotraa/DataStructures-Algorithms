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
  vector<int> pre;
  vector<vector<int>> dp;
  int helper(vector<int> &arr, int i, int j)
  {
    if (i >= j)
    { // base case , element should be atleat one to divide the array.
      return 0;
    }
    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }
    int ans = INT_MIN / 2;
    for (int k = i; k < j; k++)
    { // running loop to divide the array at each each position.
      int t1 = 0;
      int t2 = 0;
      int sum1 = (pre[j] - pre[k + 1] + arr[k + 1]); // sum of elements of  second partition array.
      int sum2 = (pre[k] - pre[i] + arr[i]);         // sum of elements of first partition array.
      if (sum1 >= sum2)
      { // According to question, we will throw the greater sum array and keep score of less sum array.
        t1 = helper(arr, i, k);
        ans = max(ans, sum2 + t1);
      }
      if (sum1 <= sum2)
      { // same here above.
        t2 = helper(arr, k + 1, j);
        ans = max(ans, sum1 + t2);
      }
    }
    return dp[i][j] = ans;
  }
  int stoneGameV(vector<int> &arr)
  {
    int n = arr.size();
    dp.assign(n, vector<int>(n, -1));
    pre.assign(n, 0);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
      pre[i] = pre[i - 1] + arr[i];
    }
    return helper(arr, 0, n - 1);
  }
};