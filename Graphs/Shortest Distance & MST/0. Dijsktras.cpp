#include <bits/stdc++.h>
using namespace std;

/*
Greedy | Graph | Priority Queue (heap)

Things ypu have to take case

1. If Priority Queue is with pair and you are creating min heap with just pair
   make sure pq - pair has this structure -> { wt, node }
2. The adjacency list could usually has structure { node, wt} so be careful with that 
*/

class Solution
{
private:
  vector<vector<pair<int, int>>> buildGraph(vector<vector<int>> edgeList, int n)
  {
    vector<vector<pair<int, int>>> adjList(n);
    for (vector<int> edges : edgeList)
    {
      int u = edges[0];
      int v = edges[1];
      int wt = edges[2];
      adjList[u].push_back({v, wt});
    }
    return adjList;
  }

public:
  int minimumPath(vector<vector<int>> &edgeList, int n, int source, int destination)
  {
    int result = INT_MAX;
    vector<vector<pair<int, int>>> adjList = buildGraph(edgeList, n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n, false);
    vector<int> dist(n, INT_MAX);
    pq.push({0, source});
    dist[source] = 0;

    while (pq.empty() == false)
    {
      int u = pq.top().second;
      pq.pop();
      visited[u] = true;

      // remove this if you want shortest path for all pairs!
      if (u == destination)
        break;

      for (pair<int, int> &neighbour : adjList[u])
      {
        int v = neighbour.first, wt = neighbour.second;
        if (visited[v] == true)
          continue;

        // relaxation of the neighbours
        if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
        {
          dist[v] = dist[u] + wt;
          pq.push({dist[v], v});
        }
      }
    }

    for (int &d : dist)
      cout << d << " ";

    return dist[destination];
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(m, vector<int>(3, 0));

  for (int i = 0; i < m; i++)
    for (int j = 0; j < 3; j++)
      cin >> arr[i][j];

  Solution *sol = new Solution();

  cout << sol->minimumPath(arr, n, 0, n - 1) << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}

/* 
INPUT:
1
7 10
0 6 7
0 1 2
1 2 3
1 3 3
6 3 3
3 5 1
6 5 1
2 5 1
0 4 5
4 6 2
*/