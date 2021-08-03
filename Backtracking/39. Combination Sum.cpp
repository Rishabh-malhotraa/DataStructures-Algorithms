//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// BackTracking | Recurssion

/*
  Input: candidates = [2,3,6,7], target = 7
  Output: [[2,2,3],[7]]
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
      list.push_back(candidates[i]);
      backtrack(i, target, sum + candidates[i], list, candidates);
      list.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    backtrack(0, target, 0, {}, candidates);
    return result;
  }
};
