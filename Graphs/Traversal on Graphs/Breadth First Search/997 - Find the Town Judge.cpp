#include <bits/stdc++.h>
using namespace std;

// components with n indegrees

class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    // a trust b
    vector<list<int>> adjList(n + 1);
    for (vector<int> &el : trust)
    {
      int u = el[0], v = el[1];
      adjList[u].push_back(v);
    }

    unordered_map<int, int> indegree;
    for (int i = 0; i <= n; i++)
    {
      for (int el : adjList[i])
      {
        indegree[el]++;
      }
    }

    int result = 0;
    int idx = 1;
    for (pair<int, int> el : indegree)
    {
      if (el.second > result)
      {
        result = el.second;
        idx = el.first;
      }
    }
    if (result == n - 1 && adjList[idx].size() == 0)
      return idx;

    return -1;
  }
};