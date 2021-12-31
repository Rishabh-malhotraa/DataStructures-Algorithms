/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

/*
     -------
[1,2,3,4,5,6,7,8]
 X X X X X
k = 4    x=5



*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    int n = arr.size();
    int l = 0, r = n - k;

    while (l < r)
    {
      int mid = unsigned(l + r) >> 1;

      if (x - arr[mid] > arr[mid + k] - x)
        l = mid + 1;
      else
        r = mid;
    }
    return vector<int>(arr.begin() + l, arr.begin() + l + k);
  }
};