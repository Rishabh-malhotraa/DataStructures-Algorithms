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
  int longestValidParentheses(string brackets)
  {
    stack<int> s;
    int n = brackets.size();
    int len = 0, maxLen = 0;
    for (int i = 0; i < n; i++)
    {
      char ch = brackets[i];
      if (ch == ')' && (s.empty() == false && brackets[s.top()] == '('))
        s.pop();
      else
        s.push(i);
    }
    int curr = n, prev = 0;
    while (s.empty() == false)
    {
      prev = s.top();
      maxLen = max(maxLen, curr - prev - 1);
      curr = prev;
      s.pop();
    }
    maxLen = max(maxLen, curr);

    return maxLen;
  }
};