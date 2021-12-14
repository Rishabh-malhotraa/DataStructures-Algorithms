/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<long long> &arr, long long el, int even)
{
  for (int i = even; i < arr.size(); i += 2)
    if (arr[i] % el == 0)
      return false;
  return true;
}

long long getGCD(vector<long long> &arr, long long k, int even)
{
  for (int i = even; i < arr.size(); i += 2)
    k = __gcd(k, arr[i]);
  return k;
}

void solve()
{
  int n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  long long result = 0;
  long long c1 = getGCD(arr, arr[0], 0);
  long long c2 = getGCD(arr, arr[1], 1);

  if (isValid(arr, c1, 1))
    result = c1;
  else if (isValid(arr, c2, 0))
    result = c2;
  else
    result = 0;
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