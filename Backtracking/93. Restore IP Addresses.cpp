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
  vector<string> result;
  string dot = ".";

private:
  void dfs(string &s, int idx, string path, int dots)
  {
    int n = s.size();
    if (idx == n && dots == 4)
    {
      path.pop_back();
      result.push_back(path);
    }

    if (dots == 4)
      return;

    string value = "";
    for (int len = 0; len < 3; len++)
    {
      int i = idx + len;
      if (i >= n || isdigit(s[i]) == false || (value[0] == '0' && value.size() > 0))
        return;

      value.push_back(s[i]);
      int num = stoi(value);
      if (num >= 0 && num <= 255)
        dfs(s, i + 1, path + value + dot, dots + 1);
    }
  }

public:
  vector<string> restoreIpAddresses(string s)
  {
    if (s.size() > 12)
      return {};

    int idx = 0;
    dfs(s, idx, "", 0);
    return result;
  }
};
