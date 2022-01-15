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
  int validSubarrays(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> pos(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
      // Input: nums = [1,4,2,5,3]
      /*
        1 4 2


        0 [1] -> 5
        1 [4] -> 2
        2 [2] -> 5
        3 [5] -> 4
        4 [3] -> 5


      */
      while (!s.empty() && nums[s.top()] <= nums[i])
      {
        int idx = s.top();
        pos[idx] = i;
        s.pop();
      }
      s.push(i);
    }

    while (s.empty())
    {
      pos[s.top()] = n;
      s.pop();
    }

    int count = 0;
    for (int i = 0; i < n; i++)
      count += pos[i] - i;

    return count;
  }
};