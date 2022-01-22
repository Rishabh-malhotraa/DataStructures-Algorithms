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
  int numberOfArrays(vector<int> &differences, int lower, int upper)
  {
    long long value = lower;
    long long maxValue = lower, minValue = lower;
    for (int difference : differences)
    {
      // x1 - value = difference
      value = difference + value;
      maxValue = max(value, maxValue);
      minValue = min(value, minValue);
    }
    long long maxDiff = upper - lower;
    long long delta = maxValue - minValue;

    if (maxDiff < delta)
      return 0;
    else
      return maxDiff + 1 - delta;
  }
};