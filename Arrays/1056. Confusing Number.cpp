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
  bool confusingNumber(int n)
  {
    unordered_set<char> s({'2', '3', '4', '5', '7'});

    string str = to_string(n);

    string str_copy = str;
    for (char &ch : str)
    {
      if (s.count(ch))
        return false;
      if (ch == '6')
        ch = '9';
      else if (ch == '9')
        ch = '6';
    }

    reverse(str.begin(), str.end());
    // cout << str << " " << str_copy << endl;
    return str != str_copy;
  }
};