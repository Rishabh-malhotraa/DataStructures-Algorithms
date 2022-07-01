/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// GREEDY || RECURSIVE || MATH

class Solution
{
public:
  int brokenCalc(int startValue, int target)
  {
    if (startValue >= target)
      return startValue - target;

    if (target % 2 == 0)
      return 1 + brokenCalc(startValue, target / 2);
    else
      return 1 + brokenCalc(startValue, target + 1);
  }
};