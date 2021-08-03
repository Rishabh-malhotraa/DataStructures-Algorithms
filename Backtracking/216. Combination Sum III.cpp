//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Find all valid combinations of `k` numbers that sum up to `n`

class Solution
{
public:
  vector<vector<int>> result;

  void backtrack(vector<int> arr, int n, int target, int start, vector<int> list)
  {
    if (target == 0 && list.size() == n)
    {
      result.push_back(list);
      return;
    }

    else if (target < 0)
      return;
    else
    {

      for (int i = start; i < arr.size(); i++)
      {
        list.push_back(arr[i]);
        backtrack(arr, n, target - arr[i], i + 1, list);
        list.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum3(int n, int target)
  {
    vector<int> arr;
    for (int i = 1; i <= 9; i++)
      arr.push_back(i);

    backtrack(arr, n, target, 0, {});

    return result;
  }
};