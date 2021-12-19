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
  int trap(vector<int> &height)
  {
    int n = height.size();
    int l = 0, r = n - 1, maxHeight = 0, currHeight = 0, totalWater = 0;
    while (l < r)
    {
      currHeight = height[(height[l] > height[r]) ? r-- : l++];
      maxHeight = max(maxHeight, currHeight);
      totalWater += maxHeight - currHeight;
    }
    return totalWater;
  }
};