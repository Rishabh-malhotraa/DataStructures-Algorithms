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
  string reorganizeString(string s)
  {
    unordered_map<char, int> freq;

    for (char &ch : s)
      freq[ch]++;

    string result = s;
    int idx = 0, nidx = 0;
    int n = result.size();
    for (auto [ch, count] : freq)
    {
      while (count--)
      {
        result[idx] = ch;
        idx = (idx + 2) % n;
      }
    }
    return result;
  }
};