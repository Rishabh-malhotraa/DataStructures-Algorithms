#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<list<pair<int, int>>> buildGraph(vector<vector<int>> &edgeList, int &n)
  {
    vector<list<pair<int, int>>> adjList(n + 1);
    for (vector<int> edges : edgeList)
    {
      int u = edges[0];
      int v = edges[1];
      int wt = edges[2];
      adjList[u].push_back({wt, v});
    }
    return adjList;
  }

public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    vector<list<pair<int, int>>> adjList = buildGraph(times, n);
    vector<bool> visited(n + 1, false);
    visited[0] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    int maxTime = INT_MIN;
    while (pq.empty() == false)
    {
      int node = pq.top().second;
      int dist = pq.top().first;
      if (visited[node] == false)
        maxTime = max(maxTime, dist);
      pq.pop();
      visited[node] = true;

      for (pair<int, int> &neighbour : adjList[node])
      {
        if (visited[neighbour.second] == false)
          pq.push({dist + neighbour.first, neighbour.second});
      }
    }
    for (bool nodeVisited : visited)
      if (nodeVisited == false)
        return -1;

    return maxTime;
  }
};
