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
    int connectSticks(vector<int> &s)
    {
      int n = s.size();
      priority_queue<int, vector<int>, greater<int>> sticks;
      for (int i = 0; i < n; i++)
        sticks.push(s[i]);

      int cost = 0;
      while (sticks.size() > 1)
      {
        int a = sticks.top();
        sticks.pop();
        int b = sticks.top();
        sticks.pop();

        cost += a + b;
        sticks.push(a + b);
      }
      return cost;
    }
  };