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

  void backtrack(vector<int> arr, int start, vector<int> list)
  {
    result.push_back(list);
    for (int i = start; i != arr.size(); i++)
    {
      if (i != start && arr[i] == arr[i - 1])
        continue;
      list.push_back(arr[i]);
      backtrack(arr, i + 1, list);
      list.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());
    backtrack(arr, 0, {});
    return result;
  }
};
