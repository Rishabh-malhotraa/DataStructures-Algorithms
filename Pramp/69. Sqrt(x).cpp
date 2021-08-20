#include <bits/stdc++.h>
using namespace std;
// 69. Sqrt(x) -> generalized to nth root of a number

class Solution
{
  double epsilon = 0.001; // margin of error

public:
  double root(double x, int n = 2)
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