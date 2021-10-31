/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int getSteps(vector<int> arr)
{

  set<int> s(arr.begin(), arr.end());

  priority_queue<int> pq(arr.begin(), arr.end());
  int steps = 0;
  set<int>::iterator it = s.lower_bound(pq.top());
  while (it != s.begin())
  {
    int top = pq.top();
    pq.pop();

    auto it = s.lower_bound(top);

    if (it == s.begin())
      return steps;

    it--, steps++;
    pq.push(*it);
  }
  return steps;
}