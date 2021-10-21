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
  vector<list<int>> buildGraph(vector<int> parentList, int n)
  {
    vector<list<int>> adjList(n);
    for (int i = 0; i < n; i++)
    {
      if (parentList[i] != -1)
        adjList[parentList[i]].push_back(i);
    }
    return adjList;
  }

  int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
  {
    int maxCost = INT_MIN, root = headID;
    vector<list<int>> graph = buildGraph(manager, n);

    queue<pair<int, int>> q({{root, informTime[root]}});
    while (q.empty() == false)
    {
      auto [node, cost] = q.front();
      maxCost = max(maxCost, cost);
      q.pop();

      for (int neigbour : graph[node])
        q.push({neigbour, cost + informTime[neigbour]});
    }
    return maxCost;
  }
};