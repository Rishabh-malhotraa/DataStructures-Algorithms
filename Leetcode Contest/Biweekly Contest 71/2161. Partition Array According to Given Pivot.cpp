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
  vector<int> pivotArray(vector<int> &nums, int pivot)
  {
    vector<int> less, eq, more;

    for (int num : nums)
    {
      if (num < pivot)
      {
        less.push_back(num);
      }
      else if (num > pivot)
      {
        more.push_back(num);
      }
      else
      {
        eq.push_back(num);
      }
    }
    vector<int> result = less;

    result.insert(result.end(), eq.begin(), eq.end());
    result.insert(result.end(), more.begin(), more.end());

    return result;
  }
};