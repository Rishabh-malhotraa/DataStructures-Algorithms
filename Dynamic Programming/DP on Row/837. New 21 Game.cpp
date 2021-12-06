/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Fibonacci type Dp with sliding window
//  DP on ROW || Math || Sliding Window || Probability
// VERY DIFFICULT QUESTION
/*
point 0 initially
while (point < K) {
  draw w  from [1, W] randomly 
  point += w
}
probability(point <= N) ?




dp[0] = 1.0 for sure

dp[1] = 1.0 / W because one of W chance we get 1

dp[2] = dp[1] / W + 1 / W we have 2 ways to get 2 here, 1 + 1 and 0 + 2

dp[3] = dp[2] / W + 1 / W


dp[11] = (dp[1] + dp[2] ... + dp[10]) * 1/W

dp[12] = (dp[2] + dp[3] ... + dp[10]) * 1/W 

- We stop the game whenever value becaomes >= K
  
  values could lie from range of [K, (K-1) + W]

  K  ... .. . ..  (K+W-1) 
                        --->always 1
  --------|-------------------|
          N                   N

*/

class Solution
{
public:
  double new21Game(int n, int k, int W)
  {
    if (k == 0 || (k + W - 1 <= n))
      return 1.0;

    double result = 0.0;
    vector<double> dp(n + 1, 0.0);
    dp[0] = 1.0;
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
    {
      if (i <= k)
      {
        sum += dp[i - 1];
      }
      if (i > W)
      {
        sum -= dp[i - W - 1];
      }

      dp[i] = sum / W;
    }

    for (int i = k; i <= n; i++)
      result += dp[i];

    return result;
  }
};