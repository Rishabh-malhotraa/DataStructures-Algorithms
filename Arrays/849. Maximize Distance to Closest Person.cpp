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
  int maxDistToClosest(vector<int> &seats)
  {
    int n = seats.size();
    int maxDistance = 0;
    vector<int> left(n,INT_MAX), right(n, INT_MAX);

    left[0] = seats.front() ? 1 : 0;
    right[n-1] = seats.back() ? 1 : 0;

    for (int i = 1; i < n; i++)
    {
      int previousIdx = max(0, i-1);
      left[i] = seats[i] == 1 ? 0 : left[previousIdx] + 1;
    }
    
    for (int i = n-1; i >= 0; i--)
    {
      int nextIdx = min(n-1, i+1);
      right[i] = seats[i] == 1 ? 0 : right[nextIdx] + 1;
    }

    for(int i =0 ; i< n ; i++)
      maxDistance = max(maxDistance, min(left[i], right[i]));

    return maxDistance;
  }
};