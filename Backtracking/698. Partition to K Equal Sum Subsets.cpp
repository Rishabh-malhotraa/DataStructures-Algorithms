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
  bool backtrack(vector<int> &nums, int target, int k, int currSum, int start, vector<bool> &visited)
  {
    if (k == 0)
      return true;

    if (currSum == target)
      return backtrack(nums, target, k - 1, 0, 0, visited);

    for (int i = start; i < nums.size(); i++)
    {
      // check
      if (visited[i] == false && currSum + nums[i] <= target)
      {
        visited[i] = true;
        if (backtrack(nums, target, k, currSum + nums[i], start + 1, visited))
          return true;
        visited[i] = false;
      }
    }
    return false;
  }

  bool canPartitionKSubsets(vector<int> &nums, int k)
  {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = sum / k;
    int maxEl = *max_element(nums.begin(), nums.end());
    if (sum % k != 0 || maxEl > target)
      return false;
    vector<bool> visited(nums.size(), false);
    return backtrack(nums, target, k, 0, 0, visited);
  }
};