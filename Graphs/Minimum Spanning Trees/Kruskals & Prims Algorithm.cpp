/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
  vector<int> parent;
  vector<int> rank;

public:
  DisjointSet(int N)
  {
    parent.resize(N, -1);
    rank.resize(N, 1);
  }

  // Find the parent of the Disjoint Set
  int find(int u)
  {
    if (parent[u] == -1)
      return u;

    else
      return parent[u] = find(parent[u]);
  }

  // Merge Two Disjoint Sets
  void Union(int u, int v)
  {
    u = find(u);
    v = find(v);

    if (u == v)
      return;
    else
    {
      if (rank[u] > rank[v])
      {
        parent[v] = u;
        rank[u] += rank[v];
      }
      else
      {
        parent[u] = v;
        rank[v] += rank[u];
      }
    }
  }

  // Checks whether two elements are in the same set or not
  bool isSameSet(int u, int v)
  {
    return (find(u) == find(v)) ? true : false;
  }

  // Count the numeber of Disjoint Sets
  int getDisjointSets()
  {
    return count(parent.begin(), parent.end(), -1);
  }

  // Get the size of the Disjoint Set
  int getRank(int u)
  {
    return rank[u];
  }

  // Get the Largest Disjoint Set
  int getMaxRank()
  {
    return *max_element(rank.begin(), rank.end());
  }
};

class MinimumSpanningTree
{
  // to get the graph just store the edges you are using in an adjacency List
  int Kruskals(int n, vector<vector<int>> &edgeList)
  {
    DisjointSet dsu(n);
    sort(edgeList.begin(), edgeList.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
    int cost = 0;
    for (vector<int> &edge : edgeList)
    {
      // nodes from 1 instead of 0 || so taking care of that
      int u = edge[0] - 1, v = edge[1] - 1;
      if (!dsu.isSameSet(u, v))
      {
        cost += edge[2];
        dsu.Union(u, v);
      }
    }
    return dsu.getDisjointSets() == 1 ? cost : -1;
  }

  int Prims(int n, vector<vector<pair<int, int>>> adjList)
  {
    vector<pair<int, int>> parent(n, {-1, INT_MAX});
    vector<bool> visited(n, false);
    parent[0] = {-1, 0};

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // wt and node
    pq.push({0, 0});

    while (!pq.empty())
    {
      pair<int, int> curr = pq.top();
      pq.pop();
      int u = curr.second;

      visited[u] = true;

      for (pair<int, int> &neighbour : adjList[u])
      {
        int v = neighbour.first, wt = neighbour.second;

        if (visited[v] == false && parent[v].second > wt)
        {
          parent[v] = make_pair(u, wt);
          pq.push({wt, v});
        }
      }
    }
    int result = 0;
    for (pair<int, int> el : parent)
      result += el.second;
    return result;
  }
};

