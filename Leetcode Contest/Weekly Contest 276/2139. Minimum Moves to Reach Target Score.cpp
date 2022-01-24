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
  int minMoves(int target, int maxDoubles)
  {
    int count = 0;
    // 2->1 -> 0
    // 2 ->4
    // 19 -> 18 -> 9 -> 8 -> 4
    while (target != 1 && maxDoubles > 0)
    {
      if (target % 2 == 1)
        target--;
      else
      {
        target = target / 2;
        maxDoubles--;
      }
      count++;
    }
    return count + target - 1;
  }
};