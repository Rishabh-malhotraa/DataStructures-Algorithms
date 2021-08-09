//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// HashMap | Concept

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_set<int> keys(nums.begin(), nums.end());
    int result = 0;
    for (int el : nums)
    {
      int prev = el - 1, count = 0;
      if (keys.find(prev) == keys.end())
      {
        int curr = el;
        while (keys.count(curr++))
          count++;

        result = max(result, count);
      }
    }
    return result;
  }
};