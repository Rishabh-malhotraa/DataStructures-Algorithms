/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Using Kadanes Algorithm

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int n = nums.size();

    vector<int> maxNums(nums), minNums(nums);

    for (int i = 1; i < n; i++)
    {
      maxNums[i] = max({nums[i], nums[i] * maxNums[i - 1], nums[i] * minNums[i - 1]});
      minNums[i] = min({nums[i], nums[i] * maxNums[i - 1], nums[i] * minNums[i - 1]});
    }
    return *max_element(maxNums.begin(), maxNums.end());
  }
};