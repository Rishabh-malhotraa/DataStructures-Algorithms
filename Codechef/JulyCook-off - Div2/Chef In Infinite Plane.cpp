// CODECHEF July Cook-off III

#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    freq[arr[i]]++;
  }

  int result = 0;

  for (auto el : freq)
  {
    int i = el.first;
    int f = el.second;
    result += min(i - 1, f);
  }

  cout << result << endl;

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