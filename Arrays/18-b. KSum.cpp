//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void twoSumRecursive(vector<int> &nums, int k, int target, int start, vector<int> temp)
{
  int n = nums.size();

  if (k == 2)
  {
    int l = start + 1;
    int r = n - 1;
    int sum = target - nums[l] - nums[r];

    if (sum < 0)
    {
      l++;
    }
    else if (sum > 0)
    {
      r++;
    }
    else
    {
      temp.push_back(l++);
      temp.push_back(r--);
      result.push_back(temp);

      while (l < r && nums[l] == nums[l - 1])
        l++;
      while (l < r && nums[r] == nums[r + 1])
        r--;
    }
  }
  else
  {
    for (int i = start; i < n; i++)
    {
      temp.push_back(nums[i]);
      twoSumRecursive(nums, k - 1, target - nums[i], start + 1, temp);
      temp.pop_back();
      while (i < n - 1 && nums[i] == nums[i + 1])
        i++;
    }
  }
}

vector<vector<int>> ksum(vector<int> nums, int k, int target)
{
  sort(nums.begin(), nums.end());
  twoSumRecursive(nums, 0, target, k, {});
  return result;
}