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
  int findShortestSubArray(vector<int> &nums)
  {
    unordered_map<int, vector<int>> cache;
    int i = 0;
    for (int &el : nums)
      cache[el].push_back(i++);

    int maxFreq = INT_MIN;
    for (auto &[num, freq] : cache)
      maxFreq = max(maxFreq, (int)freq.size());

    int shortestLength = INT_MAX;
    for (auto &[num, freq] : cache)
    {
      if (freq.size() == maxFreq)
        shortestLength = min(shortestLength, freq.back() - freq.front() + 1);
    }
    return shortestLength;
  }
};