//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;
// You don't need suffix unless you would like to make the
// approach more clean
/*
  X X X
  X X
  X
  1 2 3 7 10000



  X  X X [X X X]


  dp[][]



    1   [1 2]  [1 2 3 ]
       2  [2 3]  [2 3 7]
          3  [3 7]
             7

     1 3 6 6
       2 5 12
         3 10
           7

Alice -> 1  {}      Alice -> 2
    Bob->{}            Bob->{}
       ...
          ..
    [10,11,12,...]     [10,11,12,...]

*/

class Solution
{
public:
  string stoneGameIII(vector<int> &stoneValue)
  {
    int n = stoneValue.size();
    vector<int> dp(n + 1, INT_MIN), suffixSum(n + 1, 0);

    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
      suffixSum[i] = suffixSum[i + 1] + stoneValue[i];

    for (int i = n - 1; i >= 0; i--)
    {
      for (int k = 0; k < 3 && i + k < n; k++)
      {
        dp[i] = max(dp[i], suffixSum[i] - suffixSum[i + k + 1] + (suffixSum[i + k + 1] - dp[i + k + 1]));
      }
    }

    int result = dp[0] * 2 - suffixSum[0];
    return result > 0 ? "Alice" : result < 0 ? "Bob"
                                             : "Tie";
  }
};