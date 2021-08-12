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
  int getWinner(vector<int> &arr, int k)
  {
    int result = 0, idx = 1, count = 0;
    int n = arr.size();
    k = min(k, n);
    while (!result)
    {
      if (arr[0] > arr[idx])
        count++;
      else
      {
        swap(arr[0], arr[idx]);
        count = 1;
      }
      arr.push_back(arr[idx++]);
      if (count == k)
        result = arr[0];
    }

    return result;
  }
};