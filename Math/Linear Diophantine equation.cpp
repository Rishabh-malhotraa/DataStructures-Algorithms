#include <bits/stdc++.h>
using namespace std;

int gcd_extend(int a, int b, int &x, int &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }

  else
  {
    int g = gcd_extend(b, a % b, x, y);
    int x1 = x, y1 = y;
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
  }
}

bool isPossible = true;

pair<int, int> initialSolution(int a, int b, int c)
{
  int x, y;
  if (a == 0 && b == 0)
  {
    // if c== 0 INF sol else no sol
    isPossible = false;
    return {-1, -1};
  }
  int gcd = gcd_extend(a, b, x, y);

  if (c % gcd != 0) // numbers must be co primes
  {
    isPossible = false;
    return {-1, -1};
  }
  else
  {
    return {x * (c / gcd), y * (c / gcd)};
  }
}

// Driver Code
int main(void)
{
  int a, b, c;

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  // Given coefficients
  a = 19;
  b = 13;
  c = 20;

  int d = __gcd(a, b);
  pair<int, int> integralSolutins = initialSolution(a, b, c);

  int x0 = integralSolutins.first;
  int y0 = integralSolutins.second;

  int t = floor(((x0 - 100) * d) * 1.0 / b);

  int x1 = x0 - t * (b / d);
  int y1 = y0 + t * (a / d);

  cout << "Initial Solution" << endl;
  cout << "x: " << x0 << "  y: " << y0 << endl;

  cout << "First Intergral solution of where x > 100" << endl;
  cout << "x: " << x1 << "  y: " << y1 << endl;

  /*
  19x + 13y = 20

  x = 

  X0 - (b/gcd)t >=  100

  [X0 - 100]* gcd/b 

  Y0 + (a/gcd)t

  */

  return 0;
}
