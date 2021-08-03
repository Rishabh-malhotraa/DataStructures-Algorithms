//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

/*
Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [[1,1,6], [1,2,5], [1,7], [2,6]]
*/
class Solution
{
private:
  vector<vector<int>> result;

  void backtrack(int idx, int target, int sum, vector<int> list, vector<int> candidates)
  {
    if (sum == target)
    {
      result.push_back(list);
      return;
    }
    if (sum > target)
      return;

    for (int i = idx; i < candidates.size(); i++)
    {
      if (i != idx && candidates[i] != candidates[i - 1])
        continue;

      list.push_back(candidates[i]);
      backtrack(i + 1, target, sum + candidates[i], list, candidates);
      list.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    backtrack(0, target, 0, {}, candidates);
    return result;
  }
};
