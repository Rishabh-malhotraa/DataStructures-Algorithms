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
Find the maximum of non-intersecting segments of length 2 (two adjacent elements),
such that segments have an equal sum. For ex, given nums = [10, 1, 3, 1, 2, 2, 1, 0, 4],
there are three non-overlapping segments, each whose sum is equal to 4: (1, 3), (2, 2), (0, 4).
Expected output = 3
*/

int maxNonOverlapping(vector<int> nums)
{
  int n = nums.size();
  unordered_map<int, set<pair<int, int>>> cache;
  for (int i = 0; i < n - 1; i++)
  {
    int a = nums[i], b = nums[i + 1], sum = a + b;
    pair<int, int> el = {min(a, b), max(a, b)};
    if (cache.find(a + b) != cache.end())
    {
      
    }
    else
    {
      cache[sum].insert(el);
    }
  }
}
