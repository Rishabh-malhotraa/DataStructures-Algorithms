//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// do this in O(1) space complexity
class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
      int idx = abs(nums[i]) - 1;

      if (nums[idx] < 0)
        result.push_back(abs(idx) + 1); // to handle zero index
      else
        nums[idx] *= -1;
    }
    return result;
  }
};