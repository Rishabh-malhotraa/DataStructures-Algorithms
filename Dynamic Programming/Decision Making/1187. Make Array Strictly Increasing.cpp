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
private:
  int MAX_INT = 100000;
  int dfs(int previous, int index, vector<int> &arr1, vector<int> arr2, map<pair<int, int>, int> &cache)
  {
    if (index == arr1.size())
      return 0;
    // if (cache.find({}) != cache.end())
    //   return cache[{}];

    int arr2Index = upper_bound(arr2.begin(), arr2.end(), previous) - arr2.begin();
    if (previous >= arr1[index])
    {
      if (arr2Index == arr2.size())
        return MAX_INT;

      int cost = 1 + dfs(arr2[index], index + 1, arr1, arr2, cache);
      cache[{arr2[index], index + 1}] = cost;
      return cost;
    }

    // 2 options swap or no swap

    int noSwap = dfs(arr1[index], index + 1, arr1, arr2, cache);
    int swap = 1 + dfs(arr2[arr2Index], index + 1, arr1, arr2, cache);

    cache[{previous, index}] = min(noSwap, swap);
    return cache[{previous, index}];
    /*


       1 5              1 2

       dfs(1, 1)  -> add 1 and replace 5
            |
            |------> keep going




    */
  }

public:
  int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
  {
    sort(arr2.begin(), arr2.end());
    map<pair<int, int>, int> cache;
    int cost = dfs(-1, 0, arr1, arr2, cache);
    return cost >= MAX_INT ? -1 : cost;
  }
};