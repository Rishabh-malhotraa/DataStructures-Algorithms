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
  int lengthOfLongestSubstring(string s)
  {

    unordered_map<char, int> umap;

    int l = 0, r = 0, len = 0;

    while (r < s.size())
    {
      cout << r << "------" << l << endl;
      char ch = s[r];
      if (umap.find(ch) == umap.end())
        umap[ch] = r++;
      else
      {
        while (l <= r)
        {
          if (s[l] == ch)
          {
            umap.erase(s[l]);
            l++;
            break;
          }
          else
          {
            umap.erase(s[l]);
          }
          l++;
        }
      }

      len = max(len, r - l);
    }
    return len;
    // p   w   w   k   e   w
    //             |
    // 0   1   2   3   4   5
    // we have length as left and right and all that jazz
  }
};