/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class BoundFunctions
{
public:
  int lower_bound(vector<int> &arr, int value)
  {
    int l = 0, r = arr.size();

    while (l < r)
    {
      int mid = unsigned(l + r) >> 1;

      if (arr[mid] < value)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }

  int upper_bound(vector<int> &arr, int value)
  {
    int l = 0, r = arr.size();

    while (l < r)
    {
      int mid = unsigned(l + r) >> 1;

      if (arr[mid] <= value)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};