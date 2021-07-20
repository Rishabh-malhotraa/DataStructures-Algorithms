#include <bits/stdc++.h>
using namespace std;

class Solution
{
  double epsilon = 0.001; // margin of error

public:
  double root(double x, int n)
  {
    double lo = 0, hi = x;

    while (hi - lo > epsilon)
    {
      double mid = (hi - lo) / 2 + lo;
      double xGuess = pow(mid, n);
      if (xGuess > x)
        hi = mid;
      else
        lo = mid;
    }

    return (hi - lo) / 2 + lo;
  }
};