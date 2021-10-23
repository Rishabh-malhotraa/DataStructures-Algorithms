/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Good question | i am sure this could be done without dsu too

class UnionFind
{
private:
  vector<int> rank, parent;

public:
  UnionFind(int n)
  {
    parent.assign(n, -1);
    rank.assign(n, 1);
  }

  int find(int u)
  {
    if (parent[u] == -1)
      return u;

    return parent[u] = find(parent[u]);
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
  int getMaxRank()
  {
    return *max_element(rank.begin(), rank.end());
  }
};

void combine(UnionFind &dsu, vector<int> &arr)
{
  for (int el : arr)
  {
    dsu.Union(el - 1, el);
    // dsu.Union(el, el + 1);
  }
}

long prison(int m, int n, vector<int> h, vector<int> v)
{

  UnionFind rows(m + 1);
  UnionFind cols(n + 1);

  combine(rows, h);
  combine(cols, v);

  long w = rows.getMaxRank();
  long b = cols.getMaxRank();

  // cout << w << " rows " << endl;
  // cout << b <<  " cols " << endl;

  return w * b;
}