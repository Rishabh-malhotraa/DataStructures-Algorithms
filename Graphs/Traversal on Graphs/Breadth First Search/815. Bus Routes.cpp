/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Involved BFS

class Solution
{
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
  {
    unordered_map<int, vector<int>> lanes;
    for (int i = 0; i < routes.size(); i++)
      for (int stop : routes[i])
        lanes[stop].push_back(i);

    queue<pair<int, int>> q({{source, 0}});
    set<int> visited({source}), visitedLane;

    while (q.empty() == false)
    {
      pair<int, int> curr = q.front();
      q.pop();
      int stop = curr.first, numberOfLanes = curr.second;

      if (stop == target)
        return numberOfLanes;

      for (int lane : lanes[stop])
      {
        if (visitedLane.count(lane))
          continue;
        visitedLane.insert(lane);
        for (int city : routes[lane])
        {
          if (visited.find(city) == visited.end())
          {
            visited.insert(city);
            q.push({city, numberOfLanes + 1});
          }
        }
      }
    }

    return -1;
  }
};