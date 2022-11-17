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
  long long maximumSubarraySum(vector<int> &nums, int k)
  {
    int l = 0, r = 0, n = nums.size();
    long long sum = 0, result = 0;
    unordered_set<int> cache;

    while (r < n)
    {
      if (cache.find(nums[r]) == cache.end())
      {
        sum += nums[r];
        cache.insert(nums[r++]);
      }
      else
      {
        sum -= nums[l];
        cache.erase(nums[l++]);
      }

      if (cache.size() == k)
      {
        result = max(result, sum);
        sum -= nums[l];
        cache.erase(nums[l++]);
      }
    }

    return result;
  }
};

/*
    1 5 4 2 9 9 9
      ^

    cache = 1 5 9

    l = 0
    r = 4


*/