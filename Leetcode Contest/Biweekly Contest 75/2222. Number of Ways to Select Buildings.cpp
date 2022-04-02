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
  long long numberOfWaysHelper(string s)
  {
    // "0001100100"
    int n = s.size();
    vector<long long> c1(n + 1, 0);
    vector<long long> c2(n + 1, 0);
    for (int i = 1; i <= n; i++)
      if (s[i - 1] == '0')
        c1[i] = c1[i - 1] + 1;
      else
        c1[i] = c1[i - 1];

    for (int i = n - 1; i >= 0; i--)
      if (s[i] == '0')
        c2[i] = c2[i + 1] + 1;
      else
        c2[i] = c2[i + 1];

    long long count = 0LL;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
        count += c1[i + 1] * c2[i];
    }
    return count;
  }

public:
  long long numberOfWays(string s)
  {
    long long count = numberOfWaysHelper(s);
    for (char &ch : s)
      ch = (ch == '1') ? '0' : '1';
    count += numberOfWaysHelper(s);
    return count;
  }
};