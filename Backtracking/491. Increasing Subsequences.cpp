//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// you cannot use the sort technique here because of the order needs to be maintained!
// because we need to find the increasing subsequences :3

class Solution
{
private:
  vector<vector<int>> result;

  void backtrack(vector<int> &nums, vector<int> &list, int idx)
  {
    if (list.size() >= 2)
      result.push_back(list);

    unordered_set<int> cache;
    for (int i = idx; i < nums.size(); i++)
    {
      if ((!list.empty() && nums[i] < list.back()) || cache.count(nums[i]))
        continue;

      list.push_back(nums[i]);
      backtrack(nums, list, i + 1);
      list.pop_back();
      cache.insert(nums[i]);
    }
  }

public:
  vector<vector<int>> findSubsequences(vector<int> &nums)
  {
    vector<int> list;
    backtrack(nums, list, 0);
    return result;
  }
};