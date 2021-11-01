//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Google Question | Dynamic Programming | HashMap for dp lookup table

class Solution
{
public:
  int longestStrChain(vector<string> &words)
  {
    sort(words.begin(), words.end(), [](string &s1, string &s2)
         { return s1.size() < s2.size(); });
    unordered_map<string, int> lookup;
    int n = words.size(), result = 0;

    for (string &word : words)
    {
      int len = 1;
      for (int i = 0; i < n; i++)
      {
        string s = word.substr(0, i) + word.substr(i + 1);

        if (lookup.count(s))
          len = max(len, lookup[s] + 1);
      }
      lookup[word] = len;
      result = max(result, len);
    }
    return result;
  }
};