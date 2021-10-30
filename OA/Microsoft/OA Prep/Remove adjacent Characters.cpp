/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/
// remove adjacent ab and ajacent cd

// aaabbbcccddde ==> e

#include <bits/stdc++.h>
using namespace std;

void format(stack<pair<char, int>> &stream, vector<bool> &toAdd, char check, int i)
{
  auto &[ch, idx] = stream.top();
  if (ch == check)
  {
    toAdd[i] = toAdd[idx] = false;
    stream.pop();
  }
}

string modifyString(string s)
{
  int n = s.size();
  stack<pair<char, int>> stream;
  vector<bool> toAdd(n, true);
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'a' || s[i] == 'c')
    {
      stream.push({s[i], i});
    }
    else if (s[i] == 'b')
    {
      format(stream, toAdd, 'a', i);
    }
    else if (s[i] == 'd')
    {
      format(stream, toAdd, 'c', i);
    }
    else
    {
      s.clear();
    }
  }
  string result = "";
  for (int i = 0; i < n; i++)
    if (toAdd[i])
      result.push_back(s[i]);

  return result;
}

void solve()
{
  string s;
  cin >> s;

  cout << modifyString(s) << endl;
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