//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Two Pointer

/*
How do you handle Duplicates!!!
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

*/

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> result;
    int n = nums.size();
    sort(begin(nums), end(nums));
    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i - 1] == nums[i])
        continue;
      int l = i + 1, r = n - 1;
      while (l < r)
      {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum > 0)
          r--;
        else if (sum < 0)
          l++;
        else
        {
          result.push_back({nums[i], nums[l++], nums[r--]});
          while (l < r && nums[l] == result.back()[1])
            l++;
          while (l < r && nums[r] == result.back()[2])
            r--;
        }
      }
    }

    return result;
  }
};