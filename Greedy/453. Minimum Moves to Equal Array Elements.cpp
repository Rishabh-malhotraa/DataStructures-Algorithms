/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// the crucial idea to understand here is adding 1 too n-1 elements is equivalent to decreaseing 1 from a single element!

class Solution
{
public:
  int minMoves(vector<int> &nums)
  {
    int n = nums.size();
    int min_value = *min_element(nums.begin(), nums.end());
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    long long minValueSum = (long long)min_value * n;

    return sum - minValueSum;
  }
};