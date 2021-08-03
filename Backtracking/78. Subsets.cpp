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