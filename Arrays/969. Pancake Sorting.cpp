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
  vector<int> pancakeSort(vector<int> nums)
  {
    vector<int> result;
    int x, i;
    for (x = nums.size(); x > 0; --x)
    {
      for (i = 0; nums[i] != x; ++i)
        ;
      reverse(nums.begin(), nums.begin() + i + 1);
      result.push_back(i + 1);
      reverse(nums.begin(), nums.begin() + x);
      result.push_back(x);
    }
    return result;
  }
};