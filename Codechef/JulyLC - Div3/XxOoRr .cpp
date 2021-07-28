// DIV-3 Longe Challenge July21-III

#include <bits/stdc++.h>
using namespace std;

void countBits(int el, vector<int> &dp)
{
  int idx = 0;
  while (el > 0)
  {
    if (el & 1)
      dp[idx]++;
    el = el >> 1;
    idx++;
  }
}

int XxOoRr(vector<int> &nums, int k)
{
  vector<int> dp(32, 0);
  int result = 0;
  for (int el : nums)
    countBits(el, dp);

  for (int bits : dp)
  {
    result += ceil(bits / (k * 1.0));
  }
  return result;
}

void solve()
{

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << XxOoRr(arr, k) << endl;
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