/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Sliding Window and just like 76. Minimum Window Substring

class Solution
{
public:
  vector<int> findSubstring(string s, vector<string> &words)
  {
    vector<int> result;
    if (words.empty())
      return result;
    unordered_map<string, int> counts, record;
    for (string word : words)
    {
      counts[word]++;
    }
    int len = words[0].size(), num = words.size(), sl = s.size();
    for (int i = 0; i < len; ++i)
    {
      int left = i, sum = 0;
      record.clear();
      for (int j = i; j <= sl - len; j += len)
      {
        string word = s.substr(j, len);
        if (counts.count(word))
        {
          record[word]++;
          sum++;
          while (record[word] > counts[word])
          {
            // remove the most left word
            record[s.substr(left, len)]--;
            left += len;
            sum--;
          }
          if (sum == num)
            result.push_back(left);
        }
        else
        {
          record.clear();
          sum = 0;
          left = j + len;
        }
      }
    }
    return result;
  }
};