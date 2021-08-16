#include <bits/stdc++.h>
using namespace std;

/**
 *? Union Find || DFS || Check and merge all disjoint sets
 ** Structuring the problem is the most involved part.
 ** Relating DSU with idx of the account and email was a nice way to cleanly solve this problem
*/

class DisjointSet
{
private:
  vector<int> rank;
  vector<int> parent;

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
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
  {
    unordered_map<string, int> cache;

    int n = accounts.size();
    DisjointSet dsu(n);

    for (int i = 0; i < n; i++)
    {
      int m = accounts[i].size();
      for (int j = 1; j < m; j++)
      {
        string email = accounts[i][j];

        if (cache.find(email) == cache.end())
          cache[email] = i;
        else
          dsu.Union(cache[email], i);
      }
    }
    int len = dsu.disjointSets();
    vector<vector<string>> result(len);
    unordered_map<int, int> getIndex;
    int idx = 0;

    for (auto email : cache)
    {

      int parent = dsu.find(email.second);

      if (getIndex.count(parent))
      {
        // add to previously created account
        int result_idx = getIndex[parent];
        result[result_idx].push_back(email.first);
      }
      else
      {
        // create a new account
        getIndex[parent] = idx;
        // push name of account holder
        result[idx].push_back(accounts[parent][0]);
        // push the email
        result[idx].push_back(email.first);
        idx++;
      }
    }

    for (vector<string> &account : result)
      sort(account.begin() + 1, account.end());

    return result;
  }
};