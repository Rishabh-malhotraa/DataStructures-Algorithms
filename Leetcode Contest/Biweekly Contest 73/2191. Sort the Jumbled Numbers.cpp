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
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
  {
    int n = nums.size();
    vector<pair<int, int>> result;

    for (int i = 0; i < n; i++)
    {
      string s = to_string(nums[i]), ns;
      for (char ch : s)
        ns.push_back('0' + mapping[ch - '0']);
      result.push_back({stoi(ns), i});
    }

    sort(result.begin(), result.end());
    vector<int> arr;
    for (auto [_, i] : result)
      arr.push_back(nums[i]);

    return arr;
  }
};