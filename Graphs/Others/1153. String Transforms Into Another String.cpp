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
  bool canConvert(string s1, string s2)
  {
    if (s1 == s2)
      return true;

    unordered_map<char, char> links;

    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
      char ch1 = s1[i], ch2 = s2[i];
      if (links.count(ch1) && links[ch1] != ch2)
        return false;
      links[ch1] = ch2;
    }

    return set(s2.begin(), s2.end()).size() < 26;
  }
};
// l -> 1    c -> 1
// e -> 3    o -> 1
// t -> 1    d -> 1
// c -> 1    e -> 3
// o -> 1    t -> 1
// d -> 1    l -> 1

// a -> 2
// b -> 1
// c -> 2

// c -> 2
// d -> 1
// e -> 2