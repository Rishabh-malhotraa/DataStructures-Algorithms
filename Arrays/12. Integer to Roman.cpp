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
  vector<pair<int, string>> numerals =
      {{1, "I"},
       {4, "IV"},
       {5, "V"},
       {9, "IX"},
       {10, "X"},
       {40, "XL"},
       {50, "L"},
       {90, "XC"},
       {100, "C"},
       {400, "CD"},
       {500, "D"},
       {900, "CM"},
       {1000, "M"}};

public:
  string intToRoman(int num)
  {
    if (num == 0)
      return "";
    pair<int, string> el = *prev(upper_bound(numerals.begin(), numerals.end(), pair<int, string>{num, "ZZZ"}));
    return el.second + intToRoman(num - el.first);
  }
};
