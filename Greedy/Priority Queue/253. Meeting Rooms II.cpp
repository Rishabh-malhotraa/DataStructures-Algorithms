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
  int minMeetingRooms(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int result = INT_MAX;
    for (vector<int> &interval : intervals)
    {
      int currStartingTime = interval[0];

      while (!pq.empty() && currStartingTime >= pq.top().front())
        pq.pop();

      pq.push({interval[1], interval[0]});
      result = min(result, (int)pq.size());
    }
    return result;
  }
};