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
  bool isPossible(vector<int> &nums, int k, int h)
  {
    int cost = 0;
    for (int num : nums)
      cost += ceil((1.0 * num) / k);

    return cost <= h;
  }

  int minEatingSpeed(vector<int> &piles, int h)
  {
    sort(piles.begin(), piles.end());
    int l = 1, r = piles.back();

    while (l < r)
    {
      int mid = unsigned(l + r) >> 1;

      if (isPossible(piles, mid, h) == false)
        l = mid + 1;
      else
        r = mid;
    }

    return l;
  }
};