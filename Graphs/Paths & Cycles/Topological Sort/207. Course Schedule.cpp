/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
###  Detecting Cycles in a Graph

FOR BFS to find the cycle you need to do the indegree method and
if you fail to find an node with indegree 0 then a cycle exist!!!

*/

class Solution
{
public:
  bool acyclic(vector<list<int>> &adjMatrix, vector<bool> &visited, unordered_set<int> cache, int node)
  {
    // if the node is in the cache return false
    if (cache.count(node))
      return false;

    if (visited[node] == true)
      return true;

    visited[node] = true;
    cache.insert(node);

    for (int neighbour : adjMatrix[node])
      if (acyclic(adjMatrix, visited, cache, neighbour) == false)
        return false;

    cache.erase(node);
    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<list<int>> adjMatrix(numCourses);

    for (vector<int> &course : prerequisites)
    {
      int u = course[0], v = course[1];
      adjMatrix[v].push_back(u);
    }

    vector<bool> visited(numCourses, false);
    unordered_set<int> cache;
    bool result = true;
    for (int node = 0; node < numCourses; node++)
    {
      if (visited[node] == false && acyclic(adjMatrix, visited, cache, node) == false)
        return false;
    }
    return true;
  }
};
