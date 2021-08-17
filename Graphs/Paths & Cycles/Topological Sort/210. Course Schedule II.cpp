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
public:
  vector<int> result;

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

    result.push_back(node);
    cache.erase(node);
    return true;
  }

  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<list<int>> adjMatrix(numCourses);

    for (vector<int> &course : prerequisites)
    {
      int u = course[0], v = course[1];
      adjMatrix[v].push_back(u);
    }

    vector<bool> visited(numCourses, false);
    unordered_set<int> cache;
    for (int node = 0; node < numCourses; node++)
    {
      if (visited[node] == false && acyclic(adjMatrix, visited, cache, node) == false)
        return {};
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
