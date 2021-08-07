//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// LC Biweekly Contest 58

class Solution
{
public:
  bool checkEqual(string &s, int i)
  {
    return (s[i] == s[i + 1] && s[i + 1] == s[i + 2]);
  }
  string makeFancyString(string s)
  {
    int n = s.size();
    string ns;
    int d = 2;
    for (int i = 0; i < n; i++)
    {
      if (i + d > n || checkEqual(s, i) == false)
        ns.push_back(s[i]);
    }
    return ns;
  }
};
