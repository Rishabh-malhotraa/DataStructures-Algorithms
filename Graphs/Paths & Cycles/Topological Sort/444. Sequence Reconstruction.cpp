/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void enqueue(queue<int> &q, unordered_map<int, int> &indegree)
  {
    for (pair<int, int> el : indegree)
      if (el.second == 0)
        q.push(el.first);
  }

  unordered_map<int, set<int>> buildGraph(vector<vector<int>> connections, unordered_map<int, int> &indegree)
  {
    unordered_map<int, set<int>> adjList;
    for (vector<int> connection : connections)
    {
      int n = connection.size();
      for (int i = 0; i < n - 1; i++)
      {
        int u = connection[i];
        int v = connection[i + 1];
        if (adjList[u].find(v) == adjList[u].end())
        {
          adjList[u].insert(v);
          indegree[u] += 0, indegree[v] += 1;
        }
      }
      if (n == 1 && adjList.count(connection[0]) == 0)
      {
        adjList[connection[0]] = {};
        if (!indegree[connection[0]])
          indegree[connection[0]] = 0;
      }
    }
    return adjList;
  }

public:
  bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs)
  {
    unordered_map<int, int> indegree;

    auto adjList = buildGraph(seqs, indegree);
    queue<int> q;
    enqueue(q, indegree);

    vector<int> list;
    while (!q.empty())
    {
      if (q.size() > 1)
        return false;

      int curr = q.front();
      q.pop();

      list.push_back(curr);

      for (int neighbour : adjList[curr])
        if (--indegree[neighbour] == 0)
          q.push(neighbour);
    }

    for (auto &[node, degree] : indegree)
      if (degree)
        return false;

    return list == org;
  }
};