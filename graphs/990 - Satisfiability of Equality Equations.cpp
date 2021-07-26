#include <bits/stdc++.h>
using namespace std;

// Union Find on equations -> first process == and then !-

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
  int disjointSets()
  {
    return count(parent.begin(), parent.end(), -1);
  }
};

class Solution
{
public:
  bool equationsPossible(vector<string> &equations)
  {
    int n = equations.size();
    // * place all '==' before '!='
    sort(equations.begin(), equations.end(), [](const string &s1, const string &s2)
         { return s1[1] == '=' && s2[1] == '!'; });
    DisjointSet dsu(26);

    for (string &equation : equations)
    {
      // cout << equation << endl;
      char x = equation.front();
      char y = equation.back();
      string relation = equation.substr(1, 2);
      if (relation == "==")
      {
        dsu.Union(x - 'a', y - 'a');
      }
      else
      {
        int parentA = dsu.find(x - 'a');
        int parentB = dsu.find(y - 'a');

        if (parentA == parentB)
          return false;
      }
    }
    return true;
  }
};
