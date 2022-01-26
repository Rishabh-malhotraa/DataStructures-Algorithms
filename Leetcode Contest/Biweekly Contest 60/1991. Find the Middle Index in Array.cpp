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
  int findMiddleIndex(vector<int> &nums)
  {
    int left = 0, right = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {

      left = (i == 0) ? 0 : accumulate(nums.begin(), nums.begin() + i, 0);
      right = (i == n - 1) ? 0 : accumulate(nums.begin() + i + 1, nums.end(), 0);

      // cout << i << " " << left << " " << right << endl;
      if (left == right)
        return i;
    }

    return -1;
  }
};
