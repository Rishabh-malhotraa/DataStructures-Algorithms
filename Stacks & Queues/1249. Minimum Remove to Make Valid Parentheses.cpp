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
private:
  /*
  "())()(((" => ()()
  "(((())()" => ()()
  */

  void removeExtraOpeningBrackets(string &s, string &balenced, stack<int> &brackets)
  {
    s = balenced, balenced = "";
    int curr = brackets.top();
    for (int i = s.size() - 1; i >= 0; i--)
    {
      if (i == curr)
      {
        brackets.pop();
        curr = brackets.empty() ? -1 : brackets.top();
      }
      else
        balenced += s[i];
    }
    reverse(balenced.begin(), balenced.end());
  }

public:
  string minRemoveToMakeValid(string s)
  {
    stack<int> brackets;
    string balenced = "";
    int i = 0, n = s.size();

    int offSet = 0;

    for (int i = 0; i < n; i++)
    {
      char ch = s[i];
      if (ch == ')' && brackets.empty())
      {
        offSet++;
        continue;
      }

      if (ch == '(')
        brackets.push(i - offSet);
      else if (ch == ')')
        brackets.pop();

      balenced += ch;
    }

    if (!brackets.empty())
      removeExtraOpeningBrackets(s, balenced, brackets);

    return balenced;
  }
};