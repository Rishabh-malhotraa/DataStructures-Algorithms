//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    //  [1,2,1,3,5,6,4]
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
      int mid = unsigned(l + r) >> 1;
      if (nums[mid] < nums[mid + 1])
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};