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
  vector<string> divideString(string s, int k, char fill)
  {
    vector<string> result;
    int n = s.size();
    for (int i = 0; i < n; i += k)
    {
      string str = s.substr(i, k);
      result.push_back(str);
    }

    if (result.back().size() != k)
    {
      string str = result.back();

      while (str.size() < k)
      {
        str.push_back(fill);
      }

      result.pop_back();
      result.push_back(str);
    }

    return result;
  }
};