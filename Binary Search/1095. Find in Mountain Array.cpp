//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

/**
 * LC Hard
 * Find the pivot index and then do a trinary search
 * Do a BS on the left subpart and then do a binary search on the right
 * subpart 
 */

class MountainArray
{
  vector<int> arr;

public:
  int length()
  {
    return arr.size();
  }
  int get(int idx)
  {
    return arr[idx];
  }
};

class Solution
{
public:
  int findInMountainArray(int target, MountainArray &A)
  {
    // find peak
    int n = A.length();
    int low = 0, high = n - 1;

    // FIND THE PIVOT
    while (low < high)
    {
      int mid = unsigned(low + high) >> 1;
      if (A.get(mid) < A.get(mid + 1))
        low = mid + 1;
      else
        high = mid;
    }

    int pivot = low;
    cout << pivot << " " << A.get(pivot) << endl;
    low = 0, high = pivot;

    // Do the Binary Seach on the left sub-part
    while (low <= high)
    {
      int mid = unsigned(low + high) >> 1;
      int mid_val = A.get(mid);
      cout << mid << "  " << mid_val << endl;
      ;
      if (mid_val == target)
        return mid;
      else if (mid_val > target)
        high = mid - 1;
      else
        low = mid + 1;
    }

    // Do a Binary seach on the right subpart
    low = pivot, high = n - 1;
    while (low <= high)
    {
      int mid = unsigned(low + high) >> 1;
      int mid_val = A.get(mid);
      cout << mid << "  " << mid_val << endl;
      ;
      if (mid_val == target)
        return mid;
      else if (mid_val < target)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return -1;
  }
};
