//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    // binary search
    int n = arr.size();
    int l = 1, r = n - 2;
    while (l < r)
    {
      int mid = unsigned(l + r) >> 1;
      if (arr[mid] < arr[mid + 1])
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};