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
  int firstMissingPositive(vector<int> &nums)
  {
    int n = nums.size();

    // 3 4 -1 1
    for (int i = 0; i < n; i++)
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        swap(nums[i], nums[nums[i] - 1]);

        int i;
    for (i = 0; i < n; i++)
      if (nums[i] != i + 1)
        return i + 1;
    return i + 1;
  }
};