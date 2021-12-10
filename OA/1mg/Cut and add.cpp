/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int totalTurns(char *input1, int input2, int input3)
{
  string s(input1);

  int m = input2, n = input3;
  deque<char> dq, original;

  for (char ch : s)
  {
    original.push_back(ch);
    dq.push_back(ch);
  }

  int move = 0;
  int turns = 0;
  while (true)
  {
    if (dq == original && turns != 0)
      return turns;
    int len = (move % 2 == 0) ? m : n;
    for (int end = s.size(), i = 0; i < len; i++, end--)
    {
      char ch = dq.back();
      dq.pop_back();
      dq.push_front(ch);
    }
    turns++, move++;
  }
}

void solve()
{
  char *s;
  cin >> s;
  int m, n;
  cin >> m >> n;

  cout << totalTurns(s, m, n) << endl;

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