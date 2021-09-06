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
  vector<vector<int>> result;

  void backtrack(int start, vector<int> arr, vector<int> list)
  {
    if (start > arr.size())
      return;

    result.push_back(list);
    for (int i = start; i < arr.size(); i++)
    {
      list.push_back(arr[i]);
      backtrack(i + 1, arr, list);
      list.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums)
  {
    backtrack(0, nums, {});
    return result;
  }
};

// --------------------------------

// using Bit masking TC: O(n*2^n)
class Solution
{
  vector<vector<int>> subsets(vector<int> &nums)
  {
    int n = 1 << nums.size();
    vector<vector<int>> result;
    for (int i = 0; i < n; i++)
    {
      vector<int> subset;
      for (int j = 0; j < nums.size(); j++)
        if ((1 << j) & i)
          subset.push_back(nums[i]);

      result.push_back(subset);
    }
    return result;
  }
};