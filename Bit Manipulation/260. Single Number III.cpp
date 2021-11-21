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
  vector<int> singleNumber(vector<int> &nums)
  {
    long long mask = 0, n = nums.size();

    for (int num : nums)
      mask = mask ^ num;

    int diff = mask & (-mask), newMask = 0;

    for (int num : nums)
      newMask = (diff & num) ? newMask ^ num : newMask;

    return {newMask, (int)mask ^ newMask};
  }
};