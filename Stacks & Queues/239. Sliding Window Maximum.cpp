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
  vector<int> maxSlidingWindow(vector<int> &arr, int k)
  {
    int n = arr.size();
    deque<int> dq;
    vector<int> result;
    // 1. remove element before adding if smaller
    // 2. remove front if size window exceeds
    // 3. push elements-index after first window created into the result array
    //
    for (int i = 0; i < n; i++)
    {
      if (!dq.empty() && i - k >= dq.front())
        dq.pop_front();
      while (!dq.empty() && arr[dq.back()] < arr[i])
        dq.pop_back();

      dq.push_back(i);

      if (i >= k - 1)
        result.push_back(arr[dq.front()]);
    }

    return result;
  }
};