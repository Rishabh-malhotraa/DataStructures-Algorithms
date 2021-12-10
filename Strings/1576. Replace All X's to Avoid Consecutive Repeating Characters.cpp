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
  string modifyString(string s)
  {
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '?')
      {
        for (char ch = 'a'; ch <= 'c'; ch++)
        {
          if (i > 0 && s[i - 1] == ch)
            continue;
          if (i + 1 < n && s[i + 1] == ch)
            continue;
          s[i] = ch;
          break;
        }
      }
    }
    return s;
  }
};