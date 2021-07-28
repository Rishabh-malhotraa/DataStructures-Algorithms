// CODECHEF July Cook-off II

#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());
  int el = arr.back();

  for (int i = 0; i < arr.size(); i++)
    arr[i] = el ^ arr[i];

  int result = 0;
  for (int val : arr)
    result = result | val;

  cout << el << " " << result << endl;

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