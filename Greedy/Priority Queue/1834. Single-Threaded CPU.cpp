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
  vector<int> getOrder(vector<vector<int>> &tasks)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> enqueue;
    vector<int> order;
    int n = tasks.size();
    for (int i = 0; i < n; i++)
      tasks[i].push_back(i);

    sort(tasks.begin(), tasks.end());

    int i = 0, endTime = 0;

    while (i < n)
    {

      if (enqueue.empty() == true)
      {
        endTime += tasks[i][0];
        enqueue.push({tasks[i][1], tasks[i][2]}), i++;
        continue;
      }

      auto [processingTime, idx] = enqueue.top();
      endTime += processingTime;
      order.push_back(idx);
      enqueue.pop();

      while (i < n && tasks[i][0] <= endTime)
      {
        enqueue.push({tasks[i][1], tasks[i][2]});
        i++;
      }
    }

    while (enqueue.empty() == false)
      order.push_back(enqueue.top().second), enqueue.pop();

    return order;
  }
};