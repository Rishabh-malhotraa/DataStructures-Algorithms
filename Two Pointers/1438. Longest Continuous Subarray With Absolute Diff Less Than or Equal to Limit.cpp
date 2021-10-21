/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|
*/

#include <bits/stdc++.h>
using namespace std;

/*
          |
[10,4,2,1,7, 9,2] 5
        |
*/

class Solution
{
private:
  bool isValidDiff(multiset<int> &list, int target, int limit)
  {
    int minVal = *list.begin();
    int maxVal = *list.rbegin();
    return ((abs(target - minVal) <= limit) && (abs(maxVal - target)) <= limit);
  }

public:
  int longestSubarray(vector<int> &nums, int limit)
  {

    int result = INT_MIN;
    multiset<int> list;
    int l = 0, r = 0, n = nums.size();

    while (r < n)
    {
      int target = nums[r];

      while (!list.empty() && isValidDiff(list, target, limit) == false)
        list.erase(list.lower_bound(nums[l++]));

      list.insert(nums[r++]);

      result = max(result, (int)list.size());
    }
    return result;
  }
};