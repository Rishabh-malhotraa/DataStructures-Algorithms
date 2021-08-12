//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

/*
class Solution
{
public:
  bool stoneGame(vector<int> &piles)
  {
    return true;
  }
};
*/

class Solution
{
public:
  bool stoneGame(vector<int> &piles)
  {
    int sum = accumulate(piles.begin(), piles.end(), 0);
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int gap = 1; gap < n; gap++)
    {
      for (int i = 0, j = gap; j < n; j++, i++)
      {
        if (gap == 0)
        {
          dp[i][j] = piles[i];
        }
        else if (gap == 1)
        {
          dp[i][j] = max(piles[i], piles[j]);
        }
        else
        {
          int val1 = piles[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
          int val2 = piles[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
          dp[i][j] = max(val1, val2);
        }
      }
    }
    return dp[0][n - 1] > sum - dp[0][n - 1];
  }
};