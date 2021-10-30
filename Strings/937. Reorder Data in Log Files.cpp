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
  vector<string> reorderLogFiles(vector<string> &logs)
  {
    vector<string> digitLogs, ans;
    vector<pair<string, string>> letterLogs;
    for (string &s : logs)
    {
      int i = 0;
      while (s[i] != ' ')
        ++i;
      if (isalpha(s[i + 1]))
        letterLogs.emplace_back(s.substr(0, i), s.substr(i + 1));
      else
        digitLogs.push_back(s);
    }
    sort(letterLogs.begin(), letterLogs.end(), [&](auto &a, auto &b)
         { return a.second == b.second ? a.first < b.first : a.second < b.second; });
    for (auto &p : letterLogs)
      ans.push_back(p.first + " " + p.second);
    for (string &s : digitLogs)
      ans.push_back(s);
    return ans;
  }
};