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
  int countQuadruplets(vector<int> &nums)
  {
    int n = nums.size();
    set<vector<int>> s;
    for (int a = 0; a < n; a++)
      for (int b = a + 1; b < n; b++)
        for (int c = b + 1; c < n; c++)
          for (int d = c + 1; d < n; d++)
            if (nums[d] == nums[a] + nums[b] + nums[c])
              s.insert({a, b, c, d});

    return s.size();
  }
};