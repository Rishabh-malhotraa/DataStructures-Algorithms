/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;
/*
Input: s = "abab", p = "ab"

freq ->
sliding window esk 
*/

class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    unordered_map<char, int> target, current;
    vector<int> result;
    int idx = 0, count = 0;

    for (char &ch : p)
      target[ch]++, current[s[idx++]]++;

    for (auto [ch, freq] : current)
      count += min(target[ch], freq);

    int n = s.size(), m = p.size();
    for (int i = idx; i < n; i++)
    {
      if (count == m)
        result.push_back(i - m);

      char remove = s[i - m], add = s[i];

      int cost = 0;

      if (--current[remove] < target[remove])
        cost += -1;
      if (++current[add] <= target[add])
        cost += 1;

      count += cost;
    }

    if (count == m)
      result.push_back(n - m);

    return result;
  }
};
// count -= (min(target[remove], current[remove]) + min(target[add], current[add]));
// current[remove]--, current[add]++;
// count += (min(target[remove], current[remove]) + min(target[add], current[add]));