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
  int getArea(vector<int> &nums, int k)
  {
    set<int> s({0});
    int area = INT_MIN;

    int currSum = 0;
    for (int num : nums)
    {
      currSum += num;
      int key = currSum - k;

      auto it = s.lower_bound(key);

      if (it != s.end())
        area = max(area, num - *it);

      s.insert(currSum);
    }

    return area;
  }

public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
  {
    int m = matrix.size(), n = matrix[0].size(), area = INT_MIN;
    for (int left = 0; left < n; left++)
    {
      vector<int> sum(m, 0);
      for (int right = 0; right < n; right++)
      {
        for (int i = 0; i < m; i++)
        {
          sum[i] += matrix[i][right];
        }

        // do something here

        area = max(area, getArea(sum, k));
      }
    }
    return area;
  }
};