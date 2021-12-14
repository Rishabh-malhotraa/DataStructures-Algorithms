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
  string rearrangeString(string s, int k)
  {
    if (k == 0)
      return s;

    string str;
    int n = s.size();
    unordered_map<char, int> freq;
    priority_queue<pair<int, char>> pq;
    for (char &ch : s)
      freq[ch]++;

    for (auto [ch, count] : freq)
      pq.push({count, ch});

    while (pq.empty() == false)
    {
      int len = min(n, k);
      vector<pair<int, char>> cache;
      for (int i = 0; i < len; i++)
      {
        if (pq.empty())
          return "";
        auto [count, ch] = pq.top();
        str.push_back(ch);

        if (--count > 0)
          cache.push_back({count, ch});
        pq.pop();
        n--;
      }

      for (auto el : cache)
        pq.push(el);
    }
    return str;
  }
};