/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3

class Solution
{

public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    int n = nums.size();
    multiset<int, greater<int>> window;

    // the end iterator is not included man!
    window.insert(nums.begin(), nums.begin() + k);

    vector<int> result;
    for (int i = k; i < n; i++)
    {
      result.push_back(*window.begin());
      window.erase(window.find(nums[i - k]));
      window.insert(nums[i]);
    }

    result.push_back(*window.begin());
    return result;
  }
};