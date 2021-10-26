/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*

0 0 0 1 2 0     zeroes
0 0 1 1 0
3 2 1 1 1 0   ones

*/

class Solution
{
public:
  int minFlipsMonoIncr(string s)
  {
    int n = s.size(), flips = INT_MAX;
    vector<int> ones(n + 1, 0), zeroes(n + 1, 0);

    for (int i = 1; i < n + 1; i++)
    {
      zeroes[i] = zeroes[i - 1] + (s[i - 1] == '0' ? 0 : 1);
    }

    for (int i = n - 1; i >= 0; i--)
    {
      ones[i] = ones[i + 1] + (s[i] == '1' ? 0 : 1);
    }

    for (int i = 1; i < n; i++)
      flips = min(flips, zeroes[i - 1] + ones[i + 1]);

    return flips;
  }
};