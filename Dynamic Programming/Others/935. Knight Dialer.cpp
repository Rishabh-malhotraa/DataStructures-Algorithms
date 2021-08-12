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
  int knightDialer(int n)
  {
    int result = 0;
    long long mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(10, 0));
    vector<vector<int>> graph = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};

    dp[1] = vector<int>(10, 1);

    for (int i = 2; i <= n; i++)
    {
      // start placing knight on each digit starting from 0
      for (int j = 0; j < 10; j++)
      {
        // graph[0] = {4,6}
        // meaning add the n.o.w to get to 0 from 4 & 6 from n-1 steps
        for (int neighbour : graph[j])
        {
          dp[i][j] = (dp[i][j] + dp[i - 1][neighbour]) % mod;
        }
      }
    }
    for (int el : dp[n])
      result = (result % mod + el % mod) % mod;

    return result;
  }
};