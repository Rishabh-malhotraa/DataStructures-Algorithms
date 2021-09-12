/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/


#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int M1 = *max_element(arr.begin(), arr.end());

  int k_max = count(arr.begin(), arr.end(), M1);
  int k = count(arr.begin(), arr.end(), M1 - 1);

  long long total = 1, invalid = 1;
  for (int i = 1; i <= n; i++)
  {
    total = (total * i) % MOD;
    if (i != k + 1)
      invalid = (invalid * i) % MOD;
  }

  if (k_max > 1)
    return total;
  else
    return (total - invalid + MOD) % MOD;
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
    cout << solve() << endl;
  }
  return 0;
}

/*

THIS DID NOT WORK BECAUSE OF MODULAR DIVISION

YOU CANT DIVIDE LIKE THIS -> YOU NEED TO DO MODULAR DIVISION OR JUST NOT THAT GIVEN NUMBER 

return (factorial[n] - (factorial[n] / (k + 1)));




#include <bits/stdc++.h>
using namespace std;

int N = 2 * (1e6);
long long MOD = 998244353;
vector<long long> factorial(N + 1);

long long solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int M1 = *max_element(arr.begin(), arr.end());

  int k_max = count(arr.begin(), arr.end(), M1);
  int k = count(arr.begin(), arr.end(), M1 - 1);

  if (k_max > 1)
    return factorial[n];
  else
    return (factorial[n] - (factorial[n] / (k + 1)));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  for (int i = 1; i <= N; i++)
    factorial[i] = (factorial[i - 1] * i) % MOD;

  int t;
  cin >> t;
  while (t--)
  {
    cout << solve() << endl;
  }
  return 0;
}

*/