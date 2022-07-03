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
  int wiggleMaxLength(vector<int> &nums)
  {
    int up = 1, down = 1, n = nums.size();

    for (int i = 1; i < nums.size(); i++)
      if (nums[i] - nums[i - 1] > 0)
        up = 1 + down;
      else if (nums[i] - nums[i - 1] < 0)
        down = 1 + up;
    return max(up, down);
  }
};
