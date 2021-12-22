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
  vector<int> searchRange(vector<int> &nums, int target)
  {
    auto it = nums.begin();
    int n = nums.size();
    bool result = binary_search(it, nums.end(), target);

    if (result == false)
      return {-1, -1};

    int ll = lower_bound(nums.begin(), nums.end(), target) - it;
    int ul = upper_bound(nums.begin(), nums.end(), target) - it - 1;
    // ll = ll == n? -1 : ll;
    // ul = ul == n? -1 : ul - 1;

    return {ll, ul};
  }
};