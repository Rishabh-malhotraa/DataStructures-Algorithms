// DIV-3 Longe Challenge July21-V

#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int len = (int)1e5 + 1;

vector<long long> dp(len, 0);
vector<long long> prefixSum(len, 0);

long long getChefora(int i)
{
  long long num = i;

  long long result = num;
  if (num < 10)
    result = num;
  else
  {
    num = num / 10;
    while (num != 0)
    {
      result = result * 10 + num % 10;
      num = num / 10;
    }
  }
  return result;
}

int chefora(int l, int r)
{
  long long x = dp[l];
  long long y = prefixSum[r] - prefixSum[l];

  long long result = 1;
  while (y > 0)
  {
    if (y & 1)
    {
      // odd
      result = (result * x) % mod;
      y--;
    }
    else
    {
      // even
      x = (x * x) % mod;
      y = y >> 1;
    }
  }

  return result;
}

void solve()
{

  int l, r;
  cin >> l >> r;

  cout << chefora(l, r) << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  for (int i = 0; i < len; i++)
  {
    dp[i] = getChefora(i);
    prefixSum[i] = prefixSum[i - 1] + dp[i];
  }

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
