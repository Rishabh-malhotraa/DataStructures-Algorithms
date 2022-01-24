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
  int n;
  bool canRun(vector<int> &batteries, long long time)
  {
    long long power = 0, powerRequired = time * n;

    for (long long battery : batteries)
    {
      power += min(time, battery);
    }
    return (power - powerRequired) >= 0;
  }

public:
  long long maxRunTime(int n, vector<int> &batteries)
  {
    this->n = n;
    int len = batteries.size();
    if (len < n)
      return 0;

    long long l = 0, r = accumulate(batteries.begin(), batteries.end(), 0LL) / n;

    while (l < r)
    {
      long long mid = (l + r + 1) / 2; // unsigned for long long is RIP T-T

      if (canRun(batteries, mid))
        l = mid;
      else
        r = mid - 1;
    }

    return l;
  }
};