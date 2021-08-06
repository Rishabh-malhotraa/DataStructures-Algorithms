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
  int threeSumClosest(vector<int> &nums, int target)
  {
    int n = nums.size();
    int result = 0, min_result = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++)
    {
      int j = i + 1, k = n - 1;
      int sum = 0, min_diff = 0;
      while (j < k)
      {
        sum = nums[i] + nums[j] + nums[k];
        min_diff = abs(target - sum);
        if (min_diff < min_result)
        {
          result = sum;
          min_result = min_diff;
        }
        if (sum > target)
        {
          k--;
        }
        else
        {
          j++;
        }
      }
    }
    return result;
  }
};