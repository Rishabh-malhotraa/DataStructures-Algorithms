/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

A useful trick (when doing any parentheses validation) is to greedily check balance left-to-right, and then right-to-left.

Left-to-right check ensures that we do not have orphan ')' parentheses.
Right-to-left checks for orphan '(' parentheses.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canBeValid(string s, string locked)
  {
    int n = s.size();

    if (n % 2 != 0)
      return false;

    int variable = 0, open = 0, closed = 0;

    for (int i = 0; i < n; i++)
    {
      if (locked[i] == '0')
        variable++;
      else if (s[i] == '(')
        open++;
      else if (s[i] == ')')
        closed++;

      // check for isolated ')'
      if (variable + open - closed < 0)
        return false;
    }

    variable = 0, open = 0, closed = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      if (locked[i] == '0')
        variable++;
      else if (s[i] == '(')
        open++;
      else if (s[i] == ')')
        closed++;

      // check for isolated '('
      if (variable - open + closed < 0)
        return false;
    }

    return true;
  }
};