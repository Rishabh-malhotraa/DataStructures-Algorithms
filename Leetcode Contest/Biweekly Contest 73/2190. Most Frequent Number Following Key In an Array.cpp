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
  int mostFrequent(vector<int> &nums, int key)
  {
    int n = nums.size();
    unordered_map<int, int> freq;
    for (int i = 1; i < n; i++)
    {
      if (nums[i - 1] == key)
        freq[nums[i]]++;
    }

    vector<pair<int, int>> result;
    for (auto [el, count] : freq)
      result.push_back({count, el});

    sort(result.begin(), result.end());

    return result.back().second;
  }
};