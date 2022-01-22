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
  int minimumCost(vector<int> &cost)
  {
    sort(cost.begin(), cost.end(), greater<int>());
    int n = cost.size();
    int pay = 0, i = 0;
    while (i < n)
    {
      pay += cost[i++];
      if (i < n)
      {
        pay += cost[i++];
        i++;
      }
    }
    return pay;
  }
};