//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  unordered_map<string, int> dp;
  bool isScramble(string s1, string s2)
  {
    int n = s1.size();

    if (s1.size() != s2.size())
      return false;

    if (s1 == s2)
      return true;

    if (s1.size() == 1)
      return false;

    string key = s1 + "," + s2;
    bool flag = false;
    if (dp.find(key) != dp.end())
      return dp[key];

    for (int i = 1; i < n; i++)
    {
      bool sameOrder = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));
      bool swapOrder = (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)));
      if (swapOrder || sameOrder)
      {
        flag = true;
        break;
      }
    }

    return dp[key] = flag;
  }
};