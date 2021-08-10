//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// If we are deleting arr[i-1] we just change
// the value of cost[i-1] to the running max.

class Solution
{
public:
  int minCost(string s, vector<int> &cost)
  {
    int result = 0, n = s.size();
    for (int i = 0; i < n; i++)
    {
      if (i > 0 && s[i - 1] == s[i])
      {
        result += min(cost[i - 1], cost[i]);
        cost[i] = max(cost[i - 1], cost[i]);
      }
    }
    return result;
  }
};