/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
  long long n, t;
  cin >> n >> t;
  vector<long long> arr(n);
  queue<pair<long long, long long>> q;
  vector<bool> visited(n, false);
  for (long long i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (arr[i])
      q.push({i, 0});
  }
  vector<long long> dir = {1, -1};
  long long result = 0;

  while (!q.empty())
  {
    long long time_elapsed = q.front().second;
    long long idx = q.front().first;
    visited[idx] = true;
    q.pop();

    result += (arr[idx] + (t - time_elapsed) * 2);

    if (time_elapsed >= t)
      continue;

    for (long long d : dir)
    {
      long long nidx = (idx + d + n) % n;
      if (visited[nidx] == false && arr[nidx] == 0)
      {
        visited[nidx] = true;
        q.push({nidx, time_elapsed + 1});
      }
    }
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