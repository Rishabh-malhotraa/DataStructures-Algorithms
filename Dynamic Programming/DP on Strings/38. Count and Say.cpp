//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Recurssion | f(n) = parseString(f(n-1));

class Solution
{
public:
  string parseString(string s)
  {
    s.push_back(' ');
    int n = s.size();
    string result = "";
    int count = 1;
    char prev = s[0];
    // 11 -> 2
    for (int i = 1; i < n; i++)
    {
      if (prev != s[i])
      {
        result += to_string(count) + prev;
        prev = s[i];
        count = 1;
      }
      else
      {
        count++;
      }
    }
    return result;
  }

  string countAndSay(int n)
  {
    if (n == 1)
      return ("1");
    else
    {
      string result = countAndSay(n - 1);
      return parseString(result);
    }
  }
};
