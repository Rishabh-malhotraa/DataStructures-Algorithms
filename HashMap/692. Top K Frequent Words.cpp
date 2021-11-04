/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<string, int> a, pair<string, int> b)
{
  if (a.second == b.second)
    return a.first < b.first;

  return a.second > b.second;
}

class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    unordered_map<string, int> freq;
    vector<string> result;
    for (string &word : words)
      freq[word]++;

    vector<pair<string, int>> arr;

    for (auto el : freq)
      arr.push_back(el);

    sort(arr.begin(), arr.end(), comparator);

    for (int i = 0; i < k; i++)
      result.push_back(arr[i].first);

    return result;
  }
};