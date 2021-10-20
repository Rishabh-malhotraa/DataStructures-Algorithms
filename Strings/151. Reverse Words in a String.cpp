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
  void trim(string &s)
  {
    int l = 0, r = s.size() - 1;
    while (s[l] == ' ')
      l++;
    while (s[r] == ' ')
      r--;

    l, r++;
    r -= l;

    s = s.substr(l);
    s = s.substr(0, r);
    cout << s << endl;
  }

  string reverseWords(string s)
  {
    trim(s); // not really neccessary tbh

    stringstream ss(s);

    string token;
    vector<string> result;

    while (getline(ss, token, ' '))
    {
      if (token != "")
        result.push_back(token);
    }
    s.clear();
    for (auto it = result.rbegin(); it != result.rend(); it++)
    {
      s += *it + ' ';
    }
    s.pop_back();
    return s;
  }
};