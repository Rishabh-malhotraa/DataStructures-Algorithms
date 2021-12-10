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
  int count1(int n, unordered_map<int, int> cache)
  {
    if (n == 0)
      return 0;
    if (n <= 9)
      return 1;

    int base = pow(10, (int)log10(n));

    int count = 0;
    int quotient = n / base;
    int remainder = n % base;

    count += quotient * (cache[base - 1]);

    count += (quotient == 1) ? remainder + 1 : base;

    count += count1(remainder, cache);
    return count;
  }

public:
  int countDigitOne(int n)
  {
    unordered_map<int, int> cache;

    cache[0] = 0;
    int base = 1;
    for (long long i = 9; i <= n; i = i * 10 + 9)
    {

      int prev = i % base;
      cache[i] = cache[prev] * 10 + base;

      base *= 10;
    }
    return count1(n, cache);
  }
};