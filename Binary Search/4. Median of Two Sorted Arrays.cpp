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

Method 1 : Merge Arrays
TC : O(N + M) SC : O(N + M)
 - Merge Two Arrays and then find the median
 - Median if n is odd -> arr[N/2]
 - Median if n is even -> (arr[N/2] + arr[N/2 - 1])/ 2


Method 2: Use 2 Basket Method
TC : O(N + M) SC : O(1)

- Make 2 Bags of size
   - If n is odd  : (N/2 + 1) and N/2
   - If n is even :  N/2      and N/2

a1 = [1 3 5]
a2 = [4 9]

1     3 5
4 9

1 3   5
4     9

1 3 5  {}
{}     4 9


L1  L2
L3  L4

When creating a Bag we want all elemetns in Bag 1 to be smaller than Bag 2
- We know every element in L2 is >= L1 & every element in L4 >= L3
- so we need to just check if
    - L4(first Element) >= L1(last element)
    - L2(first Element) >= L3(last element)


Once we have Bags  sorted

If n = odd    max(L1, L3)
If n = even   max(L1, L3) + min(L2, L4) / 2

*/

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