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
  int minDifference(vector<int> &nums)
  {

    int n = nums.size();

    if (n <= 4)
    {
      return 0;
    }

    sort(nums.begin(), nums.end());
    int minVal = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
      minVal = min(minVal, abs(nums[(n - 4 + i) % n] - nums[i]));
    }

    return minVal;
    /*

    [20,66,68,57,45,18,42,34,37,58]
     X  X  X  |                 |  X  X  X
    18 20 34 37 42 45 57 58 66 68
  40
  0  1        4
  20 75 81 82 95
    *     -
  0 1 1 4 6 6 6
  */
  }
};