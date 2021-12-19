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
    int n = s.size();
    unordered_map<char, int> mp;
    vector<pair<int, char>> freq;
    for (char &ch : s)
      mp[ch]++;

    for (auto [ch, count] : mp)
      freq.push_back({count, ch});

    sort(freq.begin(), freq.end(), greater<pair<int, char>>());

    if (2 * freq.begin()->first - 1 > n)
      return "";

    string result = string(n, ' ');
    int idx = 0, nidx = 0;
    for (auto [count, ch] : freq)
    {
      while (count--)
      {
        result[idx] = ch;
        // cout << result << endl;

        idx = (idx + 2);
        if (idx >= n)
          idx = 1;
      }
    }
    return result;
  }
};