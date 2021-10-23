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
  int wordsTyping(vector<string> &sentence, int rows, int cols)
  {
    unordered_map<int, int> cache;
    int idx = 0, words = 0, n = sentence.size();
    for (int i = 0; i < rows; i++)
    {
      if (cache.find(idx) == cache.end())
      {
        int j = 0, idx_ = idx, count = 0;
        while (j + sentence[idx_].size() <= cols)
        {
          j += sentence[idx_].size() + 1;
          idx_ = (idx_ + 1) % n;
          count++;
        }
        // cout << "count: "<< count << endl;
        cache[idx] = count;
      }

      words += cache[idx];
      idx = (idx + cache[idx]) % n;
    }

    // cout << words << endl;

    return words / n;
  }
};