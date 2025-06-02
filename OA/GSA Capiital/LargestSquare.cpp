/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;


int findLargestSquareSize(vector<vector<int>> samples) {
  int n = samples.size();
  if (n == 0) return 0;

  vector<vector<int>> dp(n, vector<int>(n, 0));
  int max_side = 0;

  dp = samples;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0) {
        if (samples[i][j] == 1) {
          max_side = max(max_side, dp[i][j]);
        }
        continue;
      }

      if (samples[i][j] == 1) {
        dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
        max_side = max(max_side, dp[i][j]);
      }
    }
  }

  return max_side;
}