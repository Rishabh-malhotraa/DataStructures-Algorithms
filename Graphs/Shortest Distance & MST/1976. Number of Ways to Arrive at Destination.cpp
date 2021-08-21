/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Count the number of ways to reach the destination in minumum possible ways
// Medium - Hard because of the nuanced way of visited thingy
/*
1. You have to be smart about how you handle the visited cases
2. Use the distance measurement 
*/

class Solution
{
private:
  const int MOD = (int)1e9 + 7;
  vector<vector<pair<int, int>>> buildGraph(vector<vector<int>> edgeList, int n)
  {
    vector<vector<pair<int, int>>> adjList(n);
    for (vector<int> edges : edgeList)
    {
      int u = edges[0];
      int v = edges[1];
      int wt = edges[2];
      adjList[u].push_back({v, wt});
      adjList[v].push_back({u, wt});
    }
    return adjList;
  }

public:
  int countPaths(int n, vector<vector<int>> &grid)
  {
    vector<vector<pair<int, int>>> adjList = buildGraph(grid, n);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    vector<long long> dist(n, LONG_LONG_MAX), paths(n, 0);
    pq.push({0, 0});
    dist[0] = 0, paths[0] = 1;

    while (pq.empty() == false)
    {
      long long u = pq.top().second;
      long long nodeWt = pq.top().first;
      pq.pop();

      // rejecting all paths which may lead to greater result
      // because we aren't using visited this would act like a visited array
      // but it serves another function of having redundancy in case the distance is equal
      // between the given nodes. Because we need to count all nodes :)))
      if (nodeWt > dist[u])
        continue;
      for (pair<int, int> &neighbour : adjList[u])
      {
        long long v = neighbour.first, wt = neighbour.second;

        if (dist[v] == dist[u] + wt)
          paths[v] = (paths[u] + paths[v]) % MOD;

        // relaxation of the neighbours
        if (dist[v] > dist[u] + wt)
        {
          paths[v] = paths[u] % MOD;
          dist[v] = dist[u] + wt;
          pq.push({dist[v], v});
        }
      }
    }

    return paths.back();
  }
};
