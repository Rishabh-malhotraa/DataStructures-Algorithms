//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double myPow(double x, int n)
  {

    long power = n;
    double result = 1.0;
    if (n < 0)
    {
      x = 1 / x;
      power = -power;
    }

    for (long i = power; i > 0; i /= 2)
    {
      // in odd case we merge x
      if (i % 2 == 1)
      {
        result = result * x;
      }
      x = x * x;
    }
    return result;
  }
};

// TRASH SOLUTION MAKES NO SENSE
class Solution
{
public:
  double myPow(double x, int n)
  {
    int sign = (n > 0 ? 1 : -1);
    long long power = abs(n);
    double result = 1.0;
    while (power > 0)
    {
      bool isEven = power % 2 == 1;
      if (isEven)
      {
        x = x * x;
        power /= 2;
      }
      else
      {
        result = result * x;
        power--;
      }
    }
    return (sign < 0 ? 1 / result : result);
  }
};
