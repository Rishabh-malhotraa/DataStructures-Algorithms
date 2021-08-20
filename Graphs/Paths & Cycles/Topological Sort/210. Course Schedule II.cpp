/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

enum State
{
  UNVISITED,
  PROCESSING,
  VISITED
};

class Solution
{
private:
  vector<int> result;
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
    result.push_back(node);
    return true;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<list<int>> adjList(numCourses);

    for (vector<int> &course : prerequisites)
    {
      int u = course[0], v = course[1];
      adjList[v].push_back(u);
    }

    vector<State> visited(numCourses, UNVISITED);
    for (int node = 0; node < numCourses; node++)
      if (visited[node] == false && acyclic(node, adjList, visited) == false)
        return {};

    reverse(result.begin(), result.end());
    return result;
  }
};
