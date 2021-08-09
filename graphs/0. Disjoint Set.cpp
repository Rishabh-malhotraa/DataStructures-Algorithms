//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
  vector<int> rank, parent;

public:
  DisjointSet(int N)
  {
    parent.resize(N, -1);
    rank.resize(N, 1);
  }

  int find(int u)
  {
    if (parent[u] == -1)
      return u;

    return parent[u] = find(parent[u]);
  }

  void Union(int u, int v)
  {
    u = parent[u];
    v = parent[v];

    if (u == v)
      return;

    if (rank[u] > rank[v])
    {
      rank[u] += rank[v];
      parent[v] = u;
    }
    else
    {
      rank[u] += rank[v];
      parent[v] = u;
    }
  }
};