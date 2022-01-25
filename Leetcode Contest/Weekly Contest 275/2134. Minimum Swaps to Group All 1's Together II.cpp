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
  int minSwaps(vector<int> &nums)
  {
    // annoying way to deal with circulate arrays -> you can also use modulus and twice up the loop
    nums.insert(nums.end(), nums.begin(), nums.end());

    int k = accumulate(nums.begin(), nums.end(), 0) / 2;
    int n = nums.size();

    int window = accumulate(nums.begin(), nums.begin() + k, 0);
    int swaps = INT_MAX;
    for (int i = k; i < n; i++)
    {
      swaps = min(swaps, k - window);
      window += nums[i] - nums[i - k];
    }
    return swaps;
  }
};