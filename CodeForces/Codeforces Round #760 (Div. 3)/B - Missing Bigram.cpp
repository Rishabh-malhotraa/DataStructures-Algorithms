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
  int N;
  cin >> N;
  int n = N - 2;
  vector<string> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  string result;

  if (n == 1)
  {
    result = arr.front() + 'a';
  }
  else
  {
    result = arr[0][0];
    for (int i = 0; i < n - 1; i++)
    {
      if (arr[i][1] == arr[i + 1][0])
        result += arr[i][1];
      else
        result += arr[i][1], result += arr[i + 1][0];
    }
    result += arr.back()[1];
    if (result.size() == N - 1)
      result.push_back('a');
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