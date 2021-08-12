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
  bool canReach(vector<int> &arr, int start)
  {
    if (start < 0 || start >= arr.size() || arr[start] < 0)
      return false;
    arr[start] *= -1; // flipping same as for visited = true

    return arr[start] == 0 || canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]);
  }
};