/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Very Similar to subarray with Sum K

class Solution
{
public:
  int minSumOfLengths(vector<int> &arr, int target)
  {
    int n = arr.size(), minVal = n + 1;

    vector<int> left = getArray(arr, target);
    reverse(arr.begin(), arr.end());
    vector<int> right = getArray(arr, target);
    reverse(right.begin(), right.end());

    for (int i = 0; i < n - 1; i++)
      minVal = min(minVal, left[i] + right[i + 1]);

    return minVal == n + 1 ? -1 : minVal;
  }

  vector<int> getArray(vector<int> &arr, int target)
  {
    unordered_map<int, int> cache;
    int currSum = 0, n = arr.size();
    vector<int> result(n, 0);
    cache[0] = -1;

    for (int i = 0; i < n; i++)
    {
      int length = n + 1;
      currSum = currSum + arr[i];
      int key = currSum - target;

      if (cache.count(key) != 0)
        length = i - cache[key];

      cache[currSum] = i;
      result[i] = (i == 0 ? length : min(length, result[i - 1]));
    }
    return result;
  }
};