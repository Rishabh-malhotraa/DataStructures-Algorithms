// CODECHEF July Cook-off I

#include <bits/stdc++.h>
using namespace std;

int solve()
{
  int x, y;
  cin >> x >> y;

  if (__gcd(x, y) > 1)
    return 0;
  else if (__gcd(x + 1, y) > 1 || __gcd(x, y + 1) > 1)
    return 1;
  else
    return 2;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    cout << solve() << endl;
  }
  return 0;
}