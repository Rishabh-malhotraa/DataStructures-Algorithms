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
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    unordered_map<int, int> freq;

    int result = 0;
    int len = INT_MAX, l = 0, r = 0;
    int n = nums.size(), count = k, curr_count = 0;

    while (r < n)
    {
      int el = nums[r];
      if (freq[el] == 0)
        curr_count++;

      freq[el] += 1;

      while (curr_count == count)
      {
        if (len >= (r - l + 1))
        {
          len = r - l + 1;
          result = s.substr(l, len);
        }
        // we would want to change our left pointer here
        char el = s[l];

        if (freq.find(el) != freq.end())
        {
          freq[el]++;
          if (freq[el] > 0)
            curr_count--;
        }
        l++;
      }
      r++;
    }
    return result;
  }
};