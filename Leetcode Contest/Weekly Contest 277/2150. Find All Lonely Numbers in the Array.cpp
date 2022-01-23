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
  vector<int> findLonely(vector<int> &nums)
  {
    unordered_map<int, int> cache;
    for (int el : nums)
      cache[el]++;
    vector<int> result;
    for (int el : nums)
      if (cache.count(el - 1) == 0 && cache.count(el + 1) == 0 && cache[el] == 1)
        result.push_back(el);

    return result;
  }
};