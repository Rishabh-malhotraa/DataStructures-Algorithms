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
  string minWindow(string s, string t)
  {
    unordered_map<char, int> freq;
    for (char &ch : t)
      freq[ch]++;

    string result = "";
    int len = INT_MAX, l = 0, r = 0;
    int n = s.size(), count = t.size(), curr_count = 0;

    while (r < n)
    {
      char ch = s[r];
      if (freq.find(ch) != freq.end())
      {
        if (freq[ch] > 0)
          curr_count++;
        freq[ch]--;
      }

      while (curr_count == count)
      {
        if (len >= (r - l + 1))
        {
          len = r - l + 1;
          result = s.substr(l, len);
        }
        // we would want to change our left pointer here
        char ch = s[l];

        if (freq.find(ch) != freq.end())
        {
          freq[ch]++;
          if (freq[ch] > 0)
            curr_count--;
        }
        l++;
      }
      r++;
    }
    return result;
  }
};
