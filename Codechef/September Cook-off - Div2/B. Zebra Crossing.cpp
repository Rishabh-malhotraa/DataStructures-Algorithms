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
  int n, k;
  cin >> n >> k;
  string s;

  cin >> s;

  int Pos1 = -1, Pos0 = -1;

  // Pos0 = (n - 1) - (find(s.rbegin(), s.rend(), '0') - s.rbegin());
  // Pos1 = (n - 1) - (find(s.rbegin(), s.rend(), '1') - s.rbegin());
  Pos0 = s.find_last_of('0');
  Pos1 = s.find_last_of('1');

  // from behind --
  char previous = s[0];
  int jump = 0, i = 0;
  for (; jump < k - 1 && i < n; jump++)
  {
    char next = (previous == '0') ? '1' : '0';
    while (i < n)
      if (s[i++] == next)
        break;

    previous = next;
  }

  if (jump == k - 1)
  {
    int lastPos = (previous == '0') ? Pos1 : Pos0;
    if (i - 1 >= lastPos)
      cout << "-1" << endl;
    else
      cout << lastPos + 1 << endl;
  }
  else
  {
    cout << "-1" << endl;
  }

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