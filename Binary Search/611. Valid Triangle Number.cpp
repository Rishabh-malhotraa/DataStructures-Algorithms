//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// 2 2 3 4
// i = 1 j = 2 || lb_idx  -> 3 [res for this case would be : 3 - (1 + 1) => 1

class Solution
{
public:
  int triangleNumber(vector<int> &nums)
  {
    int n = nums.size(), result = 0;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n - 1; j++)
      {
        int ab = nums[i] + nums[j];
        auto idx = lower_bound(nums.begin() + j + 1, nums.end(), ab) - nums.begin();
        result += (idx - j - 1);
      }
    }
    return result;
  }
};

// A better O(n) solution would be to fix c and then two two pointer apporach on the remaining