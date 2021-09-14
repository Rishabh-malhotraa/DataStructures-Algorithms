/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Hash Map | String | Two Pointer | HARD
// The question becomes diffult because we want to check quality of two hasmaps in O(1) time

class Solution
{
public:
  string minWindow(string s, string t)
  {
    unordered_map<char, int> freq;
    unordered_map<char, int> window;

    for (char &ch : t)
      freq[ch]++;

    int left = 0, right = 0, lengthOfWindow = 0, minLen = INT_MAX;
    string smallestString;
    for (right = 0; right < s.size(); right++)
    {
      char ch = s[right];

      if (freq.count(ch))
      {
        window[ch]++;
        if (window[ch] <= freq[ch])
          lengthOfWindow++;
      }
      if (lengthOfWindow == t.size())
      {
        while (freq.count(s[left]) == 0 || window[s[left]] - 1 >= freq[s[left]])
        {
          if (freq.count(s[left]))
            window[s[left]]--;
          left++;
        }
        window[s[left]]--, lengthOfWindow--;
        int size = right - left + 1;
        if (size < minLen)
        {
          minLen = size;
          smallestString = s.substr(left, minLen);
        }
        left++;
      }
    }
    return smallestString;
  }
};
