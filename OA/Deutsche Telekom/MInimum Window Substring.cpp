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

/*
we are given a list of characters

1. can we have duplicates in the list of characters



shortest substring that contains [x, y, z]
freq of x = 1

freq of y  = 1

freq of z = 1

    a x y y z y z y x
          |-        |


this could be a possible result

TC: O(2N) => O(N)
SC:



x = 0
y = -1
z = 1

curr_count = 3 -> 2  []
count = 3

result = min(result, r-l);  // 4 | 7 |

x y y z y z y x
              |
           |


result = min(result, r-l)
*/

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
          if (freq[ch] >= 0)
            curr_count--;
        }
        l++;
      }
      r++;
    }
    return result;
  }
};

// Solution 2 (MEH)
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
