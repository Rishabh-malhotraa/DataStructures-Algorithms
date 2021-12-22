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
  static bool compare(string &a, string &b)
  {
    return a + b > b + a;
  }

  string largestNumber(vector<int> &nums)
  {
    vector<string> s;
    for (int el : nums)
      s.push_back(to_string(el));
    // cant user greater because 3,30 ==> 330
    // and 30 3 => 303 , in normal sort 30 and then 3
    sort(s.begin(), s.end(), compare);
    string result;
    for (string el : s)
      result += el;

    // 00 0000.. and so on
    while (result[0] == '0' && result.length() > 1)
      result.erase(0, 1);

    return result;
  }
};