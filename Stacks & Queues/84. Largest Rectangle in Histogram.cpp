//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
};