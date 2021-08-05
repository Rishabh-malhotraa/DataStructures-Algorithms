//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// this should be done using stacks even though I have implemented it using strings

class Solution
{
public:
  string evaluate(string s, int n)
  {
    string result;
    for (int i = 0; i < n; i++)
    {
      char ch = s[i];
      if (ch == '#')
      {
        if (result.size() != 0)
        {
          result.pop_back();
        }
      }
      else
      {
        result.push_back(ch);
        // result.append(ch);
        // result += ch;
      }
    }

    return result;
  }

  bool backspaceCompare(string S, string T)
  {

    string s1 = evaluate(S, S.size());
    string s2 = evaluate(T, T.size());

    return s1 == s2;
  }
};