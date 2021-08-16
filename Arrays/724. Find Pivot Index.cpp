
//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Two arrayus pref and suffix sum works
// but better is to just accumulate the sum and suffix[i] = total - prefix[i] - nums[i]

class Solution
{
public:
  int pivotIndex(vector<int> &nums)
  {
    int sum = 0, leftsum = 0;
    for (int x : nums)
      sum += x;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (leftsum == sum - leftsum - nums[i])
        return i;
      leftsum += nums[i];
    }
    return -1;
  }
};