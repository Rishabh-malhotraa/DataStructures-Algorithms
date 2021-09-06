#include <bits/stdc++.h>
using namespace std;

// UPSOLVING

void solve()
{
  int n, len;
  cin >> n >> len;
  vector<int> result;
  int d = 1;
  while (d * 10 <= n)
    d = d * 10;

  for (int i = 0; i < len - 1; i++)
  {

    while ((n - d) < len - i - 1)
      d /= 10;

    n = n - d;
    result.push_back(d);
  }

  result.push_back(n);

  for (int el : result)
    cout << el << " ";
  cout << endl;
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
    solve();
  }
  return 0;
}
