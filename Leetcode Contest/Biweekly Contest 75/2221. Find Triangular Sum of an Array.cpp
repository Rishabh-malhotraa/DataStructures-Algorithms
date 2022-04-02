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
  int triangularSum(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<int> newNums(n - 1, 0);
    for (int i = 1; i < n; i++)
      newNums[i - 1] = (nums[i] + nums[i - 1]) % 10;

    return triangularSum(newNums);
  }
};