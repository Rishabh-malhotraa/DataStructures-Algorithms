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

  string timeConversion(string s)
  {
    int n = s.size();
    string meridian = s.substr(n - 2);
    s = s.substr(0, n - 2);

    stringstream ss(s);
    vector<string> time;
    string token;

    while (getline(ss, token, ':'))
      time.push_back(token);

    if (meridian == "AM")
    {
      if (time[0] == "12")
        time[0] = "00";
    }
    else if (meridian == "PM")
    {
      if (time[0] != "12")
      {
        int time_int = stoi(time[0]) + 12;
        time[0] = to_string(time_int);
      }
    }

    s = "";
    for (string &el : time)
      s += el + ":";

    s.pop_back();
    return s;
  }
};