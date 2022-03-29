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
  vector<int> distinctNumbers(vector<int> &nums, int k)
  {
    // Input: nums = [1,2,3,2,2,1,3], k = 3
    int n = nums.size();
    unordered_map<int, int> freq;

    for (int i = 0; i < k; i++)
      freq[nums[i]]++;

    vector<int> result;
    for (int i = k; i < n; i++)
    {
      result.push_back(freq.size());
      if (--freq[nums[i - k]] == 0)
        freq.erase(nums[i - k]);
      freq[nums[i]]++;
    }

    result.push_back(freq.size());
    return result;
  }
};