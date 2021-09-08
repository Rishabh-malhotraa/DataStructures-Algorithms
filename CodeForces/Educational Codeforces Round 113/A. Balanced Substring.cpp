/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve()
{
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {0, 0}));

  for (int gap = 0; gap < n; gap++)
  {
    for (int j = gap, i = 0; j < n; i++, j++)
    {
      pair<int, int> p1 = ((s[j] == 'a') ? make_pair(1, 0) : make_pair(0, 1));
      if (j > 0)
        dp[i][j] = {dp[i][j - 1].first + p1.first,
                    dp[i][j - 1].second + p1.second};
      else
        dp[i][j] = {p1.first, p1.second};

      if (dp[i][j].first == dp[i][j].second)
        return {i + 1, j + 1};
    }
  }
  return {-1, -1};
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
    auto p1 = solve();
    cout << p1.first << " " << p1.second << endl;
  }
  return 0;
}