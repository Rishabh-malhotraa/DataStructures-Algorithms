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
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
  {
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] > b[1]; });

    int idx = 0, cost = 0;

    for (vector<int> boxType : boxTypes)
    {
      if (truckSize == 0)
        return cost;
      if (truckSize >= boxType[0])
      {
        truckSize -= boxType[0];
        cost += boxType[0] * boxType[1];
      }
      else
      {
        cost += truckSize * boxType[1];
        truckSize = 0;
      }
    }
    return cost;
  }
};