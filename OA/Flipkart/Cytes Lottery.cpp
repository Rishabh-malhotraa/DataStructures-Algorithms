/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

/*

The Cytes Lottery is the biggest lottery in the world. On each ticket, there is a string of a-z letters.
The company produces a draw string S. A person win if his/her ticket string is a special substring of the draw string.
A special substring is a substring which can be formed by ignoring at most K characters from drawString.

For example, if `draw string = “xyzabc”` and `tickets are [ac zb yhja]` with k=1 then the winning tickets will be
2 i.e ac(won by ignoring “b” in drawstring) and zb (won by ignoring “a” in drawstring).

Now, some people change their ticket string in order to win the lottery.
To avoid any kind of suspicion, they can make the following changes in their string.

They can change character ‘o’ to character ‘a’ and vice versa.
They can change character ‘t’ to character ‘I’ and vice versa.
They can erase a character from anywhere in the string.
Note that they can ignore at most ‘K’ character from the string to get a match with the ticket string.
Write an algorithm to find the number of people who win the lottery (either honestly or by cheating).

Eg. draw string = aabacd, K=2
tickets = [abcde acmfgtld]

abcde -> abcd (erase a character)abcd matches with the substring "abacd" of the draw string
(after ignoring one character)Hence, abcd will win the lottery.

*/

#include <bits/stdc++.h>
using namespace std;

// a <-> o
// t <-> i

string prepare(string s)
{
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'a' || s[i] == 'o')
      s[i] = '#';
    if (s[i] == 't' || s[i] == 'i')
      s[i] = '$';
  }
  return s;
}

bool isValid(string &s1, string &s2, int count, int i, int j, int k)
{
  cout << s1.size() << " " << s2.size() << " " << i << " " << j << " " << k << endl;
  if (i == s1.size() || j == s2.size() || k <= 0)
    return false;

  if (s1.size() - k == count)
    return true;

  if (s1[i] == s2[j])
    return isValid(s1, s2, count + 1, i + 1, j + 1, k);
  else
    return isValid(s1, s2, count, i, j + 1, k) || isValid(s1, s2, count, i + 1, j, k - 1);
}

int getTickets(vector<string> tickets, string drawString, int k)
{
  int count = 0;
  drawString = prepare(drawString);
  for (string &ticket : tickets)
  {
    ticket = prepare(ticket);
    count += (isValid(ticket, drawString, 0, 0, 0, k) ? 1 : 0);
  }
  return count;
}

void solve()
{
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  string s;
  int k;

  cin >> s;
  cin >> k;

  cout << getTickets(arr, s, k) << endl;

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