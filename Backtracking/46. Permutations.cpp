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
  void backtrack(vector<vector<int>> &result, vector<int> &nums, int idx)
  {
    if (idx == nums.size())
    {
      result.push_back(nums);
      return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
      swap(nums[idx], nums[i]);
      backtrack(result, nums, idx + 1);
      swap(nums[idx], nums[i]);
    }
  }

  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> result;

    backtrack(result, nums, 0);

    return result;
  }
};