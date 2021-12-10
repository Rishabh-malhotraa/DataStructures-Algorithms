

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

set<int> getPrimes(int &n)
{
  set<int> primes;
  vector<bool> visited(n + 1, true);
  for (int i = 2; i <= n; i++)
    if (visited[i] == true)
      for (int j = i * i; j <= n; j += i)
        visited[j] = false;

  for (int idx = 2; idx <= n; idx++)
    if (visited[idx] == true)
      primes.insert(idx);

  return primes;
}

int getGroups(int n)
{
  n += 1;
  set<int> primes = getPrimes(n);
  int count = 0;
  for (int el : primes)
  {
    if (el * 2 > n)
      count++;
  }
  return count + 1;
}

void solve()
{
  int n;
  cin >> n;
  cout << getGroups(n) << endl;

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