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
    int maxprofit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
      if (prices[i] > prices[i - 1])
        maxprofit += prices[i] - prices[i - 1];
    }
    return maxprofit;
  }
};

/*

Valleys and Hills
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int result = 0, minima = 0, maxima = 0;
    int n = prices.size(), i = 0;
    while (i < n)
    {
      while (i < n - 1 && prices[i] > prices[i + 1])
        i++;

      minima = prices[i];

      while (i < n - 1 && prices[i] < prices[i + 1])
        i++;

      maxima = prices[i];

      result += maxima - minima;
      i++;
    }
    return result;
  }
};

*/