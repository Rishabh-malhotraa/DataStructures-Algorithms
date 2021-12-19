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
  /*
  1 0 1 0 0
  2 0 2 1 1
  3 1 3 2 2   5
  4 0 0 1 0
  */

  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    stack<int> s;
    int result = 0, prevIndex = 0, area = 0;

    for (int i = 0; i <= n; i++)
    {
      int currHeight = (i == n) ? 0 : heights[i];
      while (!s.empty() && currHeight < heights[s.top()])
      {
        int h = heights[s.top()];
        s.pop();
        prevIndex = s.empty() ? -1 : s.top();
        area = (i - (prevIndex + 1)) * h;
        result = max(result, area);
      }
      s.push(i);
    }
    return result;
  }
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    if (matrix.size() == 0)
      return 0;
    int m = matrix.size(), n = matrix[0].size(), result = 0;
    vector<int> heights(n, 0);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == '0')
          heights[j] = 0;
        else
          heights[j]++;
      }
      result = max(result, largestRectangleArea(heights));
    }
    return result;
  }
};