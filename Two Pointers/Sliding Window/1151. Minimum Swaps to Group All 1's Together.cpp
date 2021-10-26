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
  int minSwaps(vector<int> &data)
  {
    int n = data.size(), l = 0, r = n - 1;
    int k = std::count(data.begin(), data.end(), 1);

    int window = std::count(data.begin(), data.begin() + k, 1);
    int maxWindow = window;
    for (int i = k; i < n; i++)
    {
      window = window - data[i - k];
      window += data[i];
      maxWindow = max(maxWindow, window);
    }
    return k - maxWindow;
  }
};
