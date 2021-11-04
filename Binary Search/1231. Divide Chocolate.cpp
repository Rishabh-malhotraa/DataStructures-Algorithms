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
private:
  int getSplits(vector<int> &sweetness, int cost)
  {
    int splits = 0, currCost = 0;
    for (int &value : sweetness)
    {
      currCost += value;

      if (currCost >= cost)
        splits++, currCost = 0;
    }

    return splits;
  }

public:
  int maximizeSweetness(vector<int> &sweetness, int k)
  {
    long long l = 1, r = accumulate(sweetness.begin(), sweetness.end(), 0LL);

    while (l < r)
    {
      int mid = unsigned(l + r + 1) >> 1;

      if (getSplits(sweetness, mid) > k)
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }
};

/*
n = 9   k = 5

       | | | | | |
1 2 3 4 5 6 7 8 9
[   ] [  ]


[n-k]
|===================|
|===================|
you have swre

for a cut to be valid

n/k

*/