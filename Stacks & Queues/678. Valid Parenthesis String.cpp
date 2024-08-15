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
  bool checkValidString(string s)
  {

    int openMax = 0, openMin = 0;
    for (char ch : s)
    {
      if (ch == '(')
        openMax++, openMin++;
      else if (ch == ')')
        openMax--, openMin--;
      else if (ch == '*')
        openMax++, openMin--;

      if (openMax < 0)
        return false;
      
      openMin = max(0, openMin);
    }
    return openMin == 0;
  }
};