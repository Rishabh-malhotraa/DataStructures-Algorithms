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
  int maxSumTwoNoOverlap(vector<int> &nums, int n, int m)
  {
    int len = nums.size();
    vector<int> prefixSum(len + 1, 0);

    for (int i = 1; i <= len; i++)
      prefixSum[i] = prefixSum[i - 1] + nums[i - 1];

    int maxValue = INT_MIN;
    int nFirst = 0, nLater = 0;
    for (int i = m + n; i <= len; i++)
    {
      /*
         [0,6, 5, 2, 2,  5,  1,  9  ,4],
        0 0 6 11 13 15  20  21  30  34
                     X

      */
      nFirst = max(prefixSum[i - m] - prefixSum[i - m - n], nFirst);
      nLater = max(prefixSum[i - n] - prefixSum[i - m - n], nLater);

      maxValue = max({maxValue, nFirst + prefixSum[i] - prefixSum[i - m], nLater + prefixSum[i] - prefixSum[i - n]});
    }

    return maxValue;
  }
};