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
  int lengthOfLongestSubstringKDistinct(string s, int k)
  {

    unordered_map<char, int> freq;
    int n = s.size();
    int l = 0, r = 0;
    int count = 0;
    int maxLen = 0;
    while (r < n)
    {
      // cout << l << " " << r << " " << count << " " << maxLen << " " << s.substr(l, r - l) << endl;

      if (count <= k)
      {
        char key = s[r++];
        if (freq[key]++ == 0)
          count++;

        if (count <= k)
          maxLen = max(maxLen, r - l);
      }
      else
      {
        while (count > k)
        {
          char key = s[l];
          if (--freq[key] == 0)
            count--;
          l++;
        }
      }
    }
    return maxLen;
  }
};