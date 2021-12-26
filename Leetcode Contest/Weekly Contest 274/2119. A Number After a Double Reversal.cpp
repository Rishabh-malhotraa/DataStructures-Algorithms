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
  bool isSameAfterReversals(int num)
  {
    string s1 = to_string(num);
    string s2 = to_string(num);

    reverse(s2.begin(), s2.end());
    int n2 = stoi(s2);

    s2 = to_string(n2);

    reverse(s2.begin(), s2.end());
    // cout << s2 <<"  " << s1 << endl;
    return s2 == s1;
  }
};