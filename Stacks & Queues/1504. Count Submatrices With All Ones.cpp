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
  int getArea(vector<int> &height)
  {
    stack<int> s;
    int area = 0;
    int n = height.size();
    vector<int> sum(n);
    for (int i = 0; i < n; i++)
    {

      while (!s.empty() && height[i] <= height[s.top()])
        s.pop();

      if (s.empty())
      {
        sum[i] = height[i] * (i + 1);
      }
      else
      {
        int prevIdx = s.top();
        sum[i] = sum[prevIdx] + (i - prevIdx) * height[i];
      }
      s.push(i);
    }

    return area;
  }

public:
  int numSubmat(vector<vector<int>> &mat)
  {
    int m = mat.size(), n = mat[0].size();
    vector<int> heights(n, 0);

    int result = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        heights[j] = (mat[i][j] == 0) ? 0 : heights[j] + mat[i][j];

      result += getArea(heights);
    }

    return result;
  }
};
