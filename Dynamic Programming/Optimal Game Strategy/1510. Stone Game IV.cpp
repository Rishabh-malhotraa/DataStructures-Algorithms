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
  bool winnerSquareGame(int n)
  {

    vector<bool> dp(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j * j <= i; j++)
      {
        if (dp[i - j * j] == false)
        {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};