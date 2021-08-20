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

enum State
{
  UNVISITED,
  PROCESSING,
  VISITED
};

class Solution
{
private:
  bool acyclic(int &node, vector<list<int>> &adjList, vector<State> &visited)
  {
    if (visited[node] == VISITED)
      return true;

    visited[node] = PROCESSING;

    for (int neighbour : adjList[node])
    {
      if (visited[neighbour] == PROCESSING)
        return false;
      if (visited[neighbour] == UNVISITED && !acyclic(neighbour, adjList, visited))
        return false;
    }
    visited[node] = VISITED;
    return true;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<list<int>> adjList(numCourses);

    for (vector<int> &prerequisite : prerequisites)
    {
      int v = prerequisite[1], u = prerequisite[0];
      adjList[v].push_back(u);
    }
    vector<State> visited(numCourses, UNVISITED);

    for (int i = 0; i < numCourses; i++)
      if (visited[i] == UNVISITED && !acyclic(i, adjList, visited))
        return false;

    return true;
  }
};

/*
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
*/