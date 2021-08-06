//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,1,1], k = 2
// Output: 2

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    unordered_map<int, int> cache = {{0, 1}};

    int sum = 0, count = 0;
    for (int &el : nums)
    {
      sum += el;
      int target = k - sum;
      count += cache[target]++;
    }
    return count;
  }
};