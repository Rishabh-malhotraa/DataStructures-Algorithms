/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int e1 = (n - 1) / 2, e2 = n - 1;

    vector<int> result = nums;
    int idx = 0;
    while (idx < n)
    {
      result[idx] = nums[e1];
      if (idx + 1 < n)
        result[idx + 1] = nums[e2];
      idx += 2, e1--, e2--;
    }

    nums = result;
    return;
  }
};