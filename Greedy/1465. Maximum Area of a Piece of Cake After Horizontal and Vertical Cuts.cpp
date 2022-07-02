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
private:
  int getMaxConsecutiveValue(vector<int> &nums, int x)
  {
    nums.push_back(x);
    sort(nums.begin(), nums.end());

    int n = nums.size(), currPos = 0, maxValue = INT_MIN;

    for (int &num : nums)
    {
      maxValue = max(maxValue, num - currPos);
      currPos = num;
    }

    return maxValue;
  }

public:
  int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
  {
    int MOD = 1e9 + 7;
    return 1LL * getMaxConsecutiveValue(horizontalCuts, h) * getMaxConsecutiveValue(verticalCuts, w) % MOD;
  }
};