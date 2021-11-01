#include <bits/stdc++.h>
using namespace std;

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/
/*
  ---------->
X   |  |  |                      Z  ---------- TARGET
    A  B  C                  |
       |-------------------->|+C---->|


X + B --> []
x + B + C -> Z -> Target

*/

class Solution
{
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
  {
    priority_queue<int> pq;
    int idx = 0, n = stations.size(), currFuel = 0;
    pq.push(startFuel);

    int stops = 0;
    while (pq.empty() == false)
    {
      currFuel += pq.top();
      pq.pop();

      if (currFuel >= target)
        return stops;

      while (idx < n && stations[idx][0] <= currFuel)
      {
        pq.push(stations[idx][1]);
        idx++;
      }
      stops++;
    }
    return -1;
  }
};