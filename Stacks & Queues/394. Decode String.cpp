#include <bits/stdc++.h>
using namespace std;

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
Input: s = "abc2[a2[bc2[d]]]"


2* (string)
  a + 2*(string)
    bc + 2*(string)


recursive do this


w = "dd"
n = ""

2  bc
2  a

Output: "accaccacc"
*/

class Solution
{
public:
  string buildString(int &idx, string &s)
  {
    int n = s.size();
    if (idx >= n)
      return "";

    string result;
    while (idx < n)
    {
      if (s[idx] == ']')
      {
        idx++;
        return result;
      }

      if (isdigit(s[idx]))
      {
        string buildDigit = string(1, s[idx]);

        while (idx + 1 < n && isdigit(s[idx + 1]))
          buildDigit += s[++idx];

        int num = stoi(buildDigit);
        idx += 2; // going from 2 to a   12[a
        string innerString = buildString(idx, s);

        while (num--)
          result += innerString;
      }
      else
        result += s[idx++];
    }
    return result;
  }

  string decodeString(string s)
  {
    int idx = 0;
    return buildString(idx, s);
  }
};

void solve()
{
  string s;
  cin >> s;

  Solution *sol = new Solution();

  cout << sol->decodeString(s);
}

int main()
{
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