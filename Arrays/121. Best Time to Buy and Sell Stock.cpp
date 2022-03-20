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
  int maxProfit(vector<int> &prices)
  {
    int minValue = INT_MAX, maxValue = 0, result = 0;

    for (int price : prices)
    {
      if (price < minValue)
      {
        minValue = maxValue = price;
      }
      else
      {
        maxValue = max(maxValue, price);
        result = max(result, maxValue - minValue);
      }
    }
    return result;
  }
};