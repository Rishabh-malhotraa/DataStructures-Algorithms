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
  vector<int> parent;
  vector<int> rank;

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

    else
      return parent[u] = find(parent[u]);
  }
  bool check(int u, int v)
  {
    return (find(u) == find(v)) ? true : false;
  }
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
  int getDisjointSets()
  {
    return count(parent.begin(), parent.end(), -1);
  }
  int getRank(int u)
  {
    return rank[u];
  }
  int getMaxRank()
  {
    return *max_element(rank.begin(), rank.end());
  }
};