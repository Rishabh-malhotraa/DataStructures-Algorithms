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
  bool canTransform(string start, string end)
  {
    string s1, s2;
    for (char &ch : start)
      s1 += ch == 'X' ? "" : to_string(ch);
    for (char &ch : end)
      s2 += ch == 'X' ? "" : to_string(ch);

    if (s1 != s2)
      return false;

    int n1 = start.size(), n2 = end.size();
    int i = 0, j = 0;
    while (i < n1 and j < n2)
    {
      if (start[i] == 'X')
        i++;
      else if (end[j] == 'X')
        j++;
      else
      {
        if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
          return false;
        i++, j++;
      }
    }
    return true;
  }
};