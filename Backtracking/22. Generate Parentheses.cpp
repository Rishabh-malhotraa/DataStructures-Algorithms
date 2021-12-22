/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> result;
  void backtrack(string curr, int n, int open, int close)
  {
    if (curr.size() == 2 * n)
      result.push_back(curr);

    if (open < n)
      backtrack(curr + "(", n, open + 1, close);
    if (close < open)
      backtrack(curr + ")", n, open, close + 1);
  }

  vector<string> generateParenthesis(int n)
  {

    backtrack("", n, 0, 0);
    return result;
  }
};