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
  int maxProfit(vector<int> &cost, int k)
  {
    int n = cost.size();
    vector<int> bp(n), sp(n);
    bp[0] = cost[0], sp[0] = 0;

    for (int i = 1; i < n; i++)
    {
      bp[i] = min(bp[i - 1], cost[i] - sp[i - 1]);
      sp[i] = max(sp[i - 1], cost[i] - bp[i - 1] - k);
    }
    return sp[n - 1];
  }
};