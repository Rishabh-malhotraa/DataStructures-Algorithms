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
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int i = 0, result = 0;

  while (i < n)
  {
    if (s1[i] != s2[i])
      result += 2;
    else
    {
      if (s1[i] == '0')
      {
        int count = 1;

        if (i + 1 < n && s1[i + 1] == '1' && s2[i + 1] == '1')
          count++, i++;

        result += count;
      }
      else if (s1[i] == '1')
      {
        int count = 0;

        if (i + 1 < n && s1[i + 1] == '0' && s2[i + 1] == '0')
          count += 2, i++;

        result += count;
      }
    }
    i++;
  }
  // std::cout << count << endl;

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