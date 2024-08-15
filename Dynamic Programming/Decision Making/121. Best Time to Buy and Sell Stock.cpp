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
  int maxProfit(vector<int> &prices)
  {
    if (prices.size() < 2)
      return 0;
    int profit = 0, maxx = prices[0], minn = prices[0];
    for (int i : prices)
    {
      if (minn > i)
      {
        minn = i, maxx = i;
      }
      else if (maxx < i)
      {
        maxx = i;
        profit = max(profit, maxx - minn);
      }
    }
    return profit;
  }
};


