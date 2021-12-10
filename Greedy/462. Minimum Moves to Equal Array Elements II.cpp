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
  int minMoves2(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    int n = nums.size();
    long long currSum = 0, minMoves = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
      currSum += nums[i];
      long long moves = ((nums[i] * (i + 1)) - currSum) + (sum - currSum - (n - i - 1) * nums[i]);

      minMoves = min(minMoves, moves);
    }

    return minMoves;
  }
};