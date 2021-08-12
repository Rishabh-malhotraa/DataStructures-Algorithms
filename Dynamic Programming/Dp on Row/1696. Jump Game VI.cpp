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
  int maxResult(vector<int> &nums, int k)
  {
    int n = nums.size(), currMax = 0;
    deque<pair<int, int>> dq;
    dq.push_back({0, nums[0]});
    for (int i = 1; i < n; i++)
    {
      currMax = dq.front().second + nums[i];
      while (!dq.empty() && currMax > dq.back().second)
        dq.pop_back();
      dq.push_back({i, currMax});
      if (i - k >= dq.front().first)
        dq.pop_front();
    }
    return dq.back().second;
  }
};
