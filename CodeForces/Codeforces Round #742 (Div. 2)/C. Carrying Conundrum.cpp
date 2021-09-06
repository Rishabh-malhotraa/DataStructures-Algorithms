/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// UPSOLVING

// SMART SOLUTION

void solve()
{
  string s;
  cin >> s;

  string s1, s2;
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
      s1.push_back(s[i]);
    else
      s2.push_back(s[i]);
  }

  long long x, y = 0;
  if (s1.size())
    x = stoll(s1);
  if (s2.size())
    y = stoll(s2);

  cout << (x + 1) * (y + 1) - 2 << endl;
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

// I am not able to understand this right now :()
void run_case()
{
  string S;
  cin >> S;
  int N = int(S.size());
  int64_t total = 0;

  for (int mask = 0; mask < 1 << N; mask += 4)
  {
    int64_t ways = 1;

    for (int i = N - 1; i >= 0; i--)
    {
      int carry_before = mask >> (i + 2) & 1;
      int carry = mask >> i & 1;
      int digit = S[i] - '0';

      if (carry_before)
      {
        if (digit == 0 && carry == 0)
        {
          ways = 0;
          break;
        }

        digit = (digit + 9) % 10;
      }

      int goal = carry ? digit + 10 : digit;

      if (carry_before && goal == 19)
        goal = 9;

      ways *= min(goal, 18 - goal) + 1;
    }

    total += ways;
  }

  cout << total - 2 << '\n';
}
