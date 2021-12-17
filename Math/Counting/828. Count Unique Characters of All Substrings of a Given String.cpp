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
In each loop, We caculate curr[i], which represent the sum of Uniq() for all substrings whose last char is S.charAt(i).

For example,
S = 'ABCBD'
When i = 2, curr[2] = Uniq('ABC') + Uniq('BC') + Uniq('C')
When i = 3, curr[3] = Uniq('ABCB') + Uniq('BCB') + Uniq('CB') + Uniq('B')

Notice, we append char 'B' into each previous substrings. Only in substrings 'CB' and 'B', the char 'B' can be identified as uniq. The contribution of 'B' from curr[2] to curr[3] is i - showLastPosition['B']. At the same time, in substrings 'ABCB', 'BCB', the char 'B' can‘t’ be identified as uniq any more, the previous contribution of 'B' should be removed.

So we have'curr[i] = curr[i - 1] - contribution[S.charAt(i)] + (i - showLastPosition[S.charAt(i)])
Then the new contribution[S.charAt(i)] = i - showLastPosition[S.charAt(i)]

The final result is the sum of all curr[i].

*/

class Solution
{
public:
  int uniqueLetterString(string s)
  {
    int n = s.size();
    // no need to convert to 0 idx lol
    vector<int> contribution(128, 0), lastPos(128, 0);
    int curr = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
      char x = s[i];
      curr -= contribution[x];
      contribution[x] = (i - (lastPos[x] - 1));
      curr += contribution[x];
      lastPos[x] = i + 1;
      count += curr;
    }
    return count;
  }
};

class Solution
{
public:
  int uniqueLetterString(string s)
  {
    const int MOD = 1e9 + 7, n = s.size();
    unordered_map<char, int> previous;
    vector<int> left(n, -1), right(n, -1);

    for (int i = 0; i < n; i++)
    {
      char ch = s[i];
      int prev_idx = (previous.find(ch) == previous.end()) ? -1 : previous[ch];
      left[i] = i - prev_idx;
      previous[ch] = i;
    }
    previous.clear();
    for (int i = n - 1; i >= 0; i--)
    {
      char ch = s[i];
      int prev_idx = (previous.find(ch) == previous.end()) ? n : previous[ch];
      right[i] = prev_idx - i;
      previous[ch] = i;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
      count = (count + (left[i] * right[i]) % MOD) % MOD;

    return count;
  }
};