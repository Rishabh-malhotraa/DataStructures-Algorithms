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
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int sum = accumulate(gas.begin(), gas.end(), 0) - accumulate(cost.begin(), cost.end(), 0);
    int n = gas.size();
    if (sum < 0)
      return -1;

    int station = 0, fuelLeft = 0;
    for (int i = 0; i < n; i++)
    {
      fuelLeft += gas[i] - cost[i];

      if (fuelLeft < 0)
      {
        station = i + 1;
        fuelLeft = 0;
      }
    }
    return station;
  }
};