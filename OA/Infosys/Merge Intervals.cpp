/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming | Merge Intervals | Burst Ballons

int getMin(int &n, vector<int> &a, vector<int> &b, vector<int> &l, vector<int> &r)
{
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int gap = 0; gap < n; gap++)
  {
    for (int i = 0, j = gap; j < n; i++, j++)
    {
      if (gap == 0)
      {
        dp[i][j] = min(a[i], b[i]);
      }
      else
      {
        int min_value = INT_MAX;
        for (int k = i; k <= j; k++)
        {
          // check if only you pay a[i]
          int left = (k == i) ? 0 : dp[i][k - 1];
          int right = (k == j) ? 0 : dp[k + 1][j];
          int cost = a[k] + left + right;

          // check if you pay b[i];

          left = ((k - 1) - l[k] < i) ? 0 : dp[i][k - l[k] - 1];
          right = ((k + 1) + r[k] > j) ? 0 : dp[k + r[k] + 1][j];

          cost = min(cost, left + right + b[k]);

          min_value = min(min_value, cost);
        }
        dp[i][j] = min_value;
      }
    }
  }
  return dp[0][n - 1];
}

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n), l(n), r(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
    cin >> l[i];
  for (int i = 0; i < n; i++)
    cin >> r[i];

  cout << getMin(n, a, b, l, r) << endl;
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