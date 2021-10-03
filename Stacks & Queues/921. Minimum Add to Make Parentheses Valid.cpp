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
  int minAddToMakeValid(string &s)
  {
    stack<char> st;
    int count = 0;
    for (char &ch : s)
    {
      if (ch == '(')
      {
        st.push('(');
      }
      else
      {
        if (!st.empty())
          st.pop();
        else
        {
          count++;
        }
      }
    }
    return count + (int)st.size();
  }
};