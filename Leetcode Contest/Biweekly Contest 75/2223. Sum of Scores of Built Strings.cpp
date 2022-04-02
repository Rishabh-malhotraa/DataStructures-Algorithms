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
  long long ZArray(string s)
  {
    int n = (int)s.length();
    vector<long long> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
      if (i <= r)
        z[i] = min((r - i + 1) * 1LL, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
      if (i + z[i] - 1 > r)
        l = i, r = i + z[i] - 1;
    }
    long long sum = 0;
    for (auto xt : z)
      sum += xt;
    return sum;
  }
  long long sumScores(string s)
  {
    return 1LL * s.size() + ZArray(s);
  }
};