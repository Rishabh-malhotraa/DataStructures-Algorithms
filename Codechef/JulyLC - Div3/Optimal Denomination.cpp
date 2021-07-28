// DIV-3 Longe Challenge July21-IV

// LONG LONG 🤮🤢

#include <bits/stdc++.h>
using namespace std;

long long optimalDenomination(vector<long long> &arr)
{
  long long n = arr.size();
  vector<long long> left_gcd(n, 1);
  vector<long long> right_gcd(n, 1);
  left_gcd[0] = arr[0];
  right_gcd[n - 1] = arr[n - 1];

  //   sort(arr.begin(), arr.end());

  for (long long i = 1; i < n; i++)
    left_gcd[i] = __gcd(left_gcd[i - 1], arr[i]);

  for (long long i = n - 2; i >= 0; i--)
    right_gcd[i] = __gcd(right_gcd[i + 1], arr[i]);

  long long max_gcd = INT_MAX;
  long long idx = 0;
  long long sum = accumulate(arr.begin(), arr.end(), 0LL);
  long long result = LONG_LONG_MAX;
  for (long long i = 0; i < n; i++)
  {

    long long left = (i == 0) ? right_gcd[i + 1] : left_gcd[i - 1];
    long long right = (i == n - 1) ? left_gcd[i - 1] : right_gcd[i + 1];

    long long curr_gcd = __gcd(left, right);
    long long curr_sum = sum - arr[i] + curr_gcd;
    // cout << curr_sum << " " << curr_gcd << endl;
    result = min(result, (curr_sum / curr_gcd));
  }

  return result;
}

void solve()
{
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++)
    cin >> arr[i];
  cout << optimalDenomination(arr) << endl;
  return;
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