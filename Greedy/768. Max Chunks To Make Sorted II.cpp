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
  int maxChunksToSorted(vector<int> &arr)
  {
    stack<int> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      int largest = (s.empty() ? arr[i] : max(arr[i], s.top()));
      while (s.empty() == false && s.top() > arr[i])
        s.pop();

      s.push(largest);
    }
    return s.size();
  }
};