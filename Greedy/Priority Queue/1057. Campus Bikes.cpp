/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Distance
{
public:
  int distance;
  int workerId;
  int bikeId;
};

class comparator
{
public:
  const bool operator()(Distance &d1, Distance d2)
  {
    // we need to have reverse order because of the way pq works my G
    return !((d1.distance < d2.distance) || (d1.distance == d2.distance && d1.workerId < d2.workerId) || (d1.distance == d2.distance && d1.workerId == d2.workerId && d1.bikeId < d2.bikeId));
  }
};

class Solution
{
public:
  vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes)
  {
    priority_queue<Distance, vector<Distance>, comparator> pq;

    int n = workers.size(), m = bikes.size();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int distance = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        pq.push({distance, i, j});
      }
    }

    vector<int> assignedBikes(n, -1);
    vector<int> bikesAvailable(m, true);

    while (pq.empty() == false)
    {
      auto [distance, workerId, bikeId] = pq.top();
      pq.pop();

      // cout << distance << " " << workerId << " " << bikeId << endl;

      if (assignedBikes[workerId] == -1 && bikesAvailable[bikeId] == true)
      {
        assignedBikes[workerId] = bikeId;
        bikesAvailable[bikeId] = false;
      }
    }

    return assignedBikes;
  }
};