//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int getScore(int l, int r, int z, vector<int> &boxes, vector<vector<vector<int>>> &dp)
  {
    if (l > r)
      return 0;

    if (dp[l][r][z] != INT_MIN)
      return dp[l][r][z];

    int k = 0;
    for (int i = l + 1; i < r && boxes[i] == boxes[i - 1]; i++)
      k++, l++;

    int result = (k + 1) * (k + 1) + getScore(l + 1, r, 0, boxes, dp);

    for (int m = l; m <= r; m++)
      if (boxes[l] == boxes[m])
        result = max(result, getScore(l + 1, m - 1, 0, boxes, dp) + getScore(m, r, k + 1, boxes, dp));

    return dp[l][r][k] = result;
  }

public:
  int removeBoxes(vector<int> &boxes)
  {
    int n = boxes.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));

    return getScore(0, n - 1, 0, boxes, dp);
  }
};

// OLD Rishabh You so DUMB

// 1. removing boxes well I dont know how you do thins which to remove before hand
// this looks tough ngl
// bands of things together
// okay but what is the intuition in here which I am unable to understand?
