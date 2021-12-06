/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Simple LIS with lookup done by hashmap
// lookup is usally done by a for [0..i] loop or doing binary search

class Solution
{
public:
  int longestSubsequence(vector<int> &arr, int difference)
  {
    unordered_map<int, int> cache;
    int result = 1, n = arr.size();
    for (int i = 0; i < n; i++)
    {
      int previous = arr[i] - difference, curr = arr[i];
      cache[curr] = max(cache[curr], cache[previous] + 1);
      result = max(result, cache[curr]);
    }
    return result;
  }
};