/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices, int cooldown = 1)
  {
    if (prices.size() == 1)
      return 0;

    int n = prices.size();
    vector<int> buy(n, 0);
    vector<int> sell(n, 0);

    buy[0] = prices[0], buy[1] = min(prices[0], prices[1]);
    sell[1] = max(0, prices[1] - buy[0]);

    for (int i = 1; i < n; i++)
    {
      int sellPrice = (i - 1 - cooldown < 0) ? 0 : sell[i - 1 - cooldown];

      buy[i] = min(buy[i - 1], prices[i] - sellPrice);
      sell[i] = max(sell[i - 1], prices[i] - buy[i - 1]);
    }

    return sell.back();
  }
};