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
  int countSegments(string s)
  {
    string token;
    stringstream ss(s);
    int count = 0;
    while (getline(ss, token, ' '))
      if (token != "")
        count++;
    return count;
  }
};

/*

class Solution {
public:
    int countSegments(string s) {
      int freq =  count(s.begin(), s.end(), ' ');
      return freq == s.size() ? 0 : freq + 1;
    }
};

this did not work because of edge cases like
"  "
"Of all the gin joints in all the towns in all the    world,"
"               "
*/