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
  string s;
  cin >> s;
  int n = s.size();
  vector<pair<char, int>> p;

  int i = 0;
  while (i < n)
  {
    int prev_i = i;
    pair<char, int> previous = {s[i], 1};

    while (s[i] == previous.first)
      previous.second++, i++;

    p.push_back(previous);
    if (prev_i == i)
      i++;
  }
  int count = 0;
  for (auto p1 : p)
  {
    if (p1.first == '0')
      count++;
  }
  int result = min(count, 2);
  std::cout << result << endl;
  return;
  // cout << "Hello world";
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