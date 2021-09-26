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
  vector<int> asteroidCollision(vector<int> &asteroids)
  {
    stack<int> s;
    int n = asteroids.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
      bool isNegative = asteroids[i] < 0 ? true : false;
      bool isDestroyed = false;
      while (!s.empty() && isNegative && !isDestroyed)
      {
        if (s.top() < abs(asteroids[i]))
          s.pop();
        else
        {
          if (s.top() + asteroids[i] == 0)
            s.pop();
          isDestroyed = true;
        }
      }

      if (!isNegative)
        s.push(asteroids[i]);
      else if (isNegative && !isDestroyed)
        result.push_back(asteroids[i]);
    }

    vector<int> temp;
    while (!s.empty())
    {
      temp.push_back(s.top());
      s.pop();
    }

    result.insert(result.end(), temp.rbegin(), temp.rend());

    return result;
  }
};