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
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size(), m = nums2.size();
    double result = 0.0;
    if (n > m)
      return findMedianSortedArrays(nums2, nums1);

    // + 1 because we want n/2 || n/2 + 1 elements in the left
    int median = (n + m + 1) >> 1;

    int l = 0, r = n;

    while (l <= r)
    {
      int mid1 = (l + r) >> 1;
      int mid2 = median - mid1;

      int l1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
      int l2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];

      int r1 = mid1 == n ? INT_MAX : nums1[mid1];
      int r2 = mid2 == m ? INT_MAX : nums2[mid2];

      if (l1 <= r2 && l2 <= r1)
      {
        if ((n + m) % 2 == 0)
          return result = (max(l1, l2) + min(r1, r2)) / 2.0;
        else
          return result = max(l1, l2);
      }
      else if (l1 > r2)
        r = mid1 - 1;
      else
        l = mid1 + 1;
    }

    return result;
  }
};

int main()
{
  return 0;
}