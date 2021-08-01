//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Two Pointers

// doing this in O(nlogn) is good but then we are not making use of the fact that this is already
// a sorted array, we can just use two pointer to check whose sqyare is bigger and push that to the
// end of the array

class Solution
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    int n = nums.size();
    int l = 0, r = n - 1;
    vector<int> result(n, 0);
    for (int idx = n - 1; idx >= 0; idx--)
    {
      int left = nums[l] * nums[l], right = nums[r] * nums[r];
      if (left < right)
      {
        result[idx] = right;
        r--;
      }
      else
      {
        result[idx] = left;
        l++;
      }
    }
    return result;
  }
};