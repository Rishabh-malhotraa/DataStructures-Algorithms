//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Sort | Greedy | Array

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {

    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
         { return a[0] < b[0]; });

    vector<vector<int>> result;
    int n = intervals.size();
    result.push_back(intervals[0]);

    for (int i = 1; i < n; i++)
    {
      vector<int> prev = result.back();
      vector<int> curr = intervals[i];

      if (curr[0] <= prev[1])
        result.back()[1] = max(prev[1], curr[1]);
      else
        result.push_back(curr);
    }

    return result;
  }
};
