//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

set<int> getPrimes(int &n)
{
  set<int> primes;
  vector<bool> visited(n, true);
  for (int i = 2; i <= n; i++)
    if (visited[i] == true)
      for (int j = i * i; j < n; j += i)
        visited[j] = false;

  for (int idx = 2; idx <= n; idx++)
    if (visited[idx] == true)
      primes.insert(idx);

  return primes;
}