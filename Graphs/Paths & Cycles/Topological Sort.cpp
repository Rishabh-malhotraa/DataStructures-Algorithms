/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class KahnsAlgorithm
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<list<int>> adjList(numCourses);
    vector<int> result;

    for (vector<int> &course : prerequisites)
    {
      int u = course[0], v = course[1];
      adjList[v].push_back(u);
    }

    vector<int> indegree(numCourses, 0);

    for (auto list : adjList)
      for (int node : list)
        indegree[node]++;

    queue<int> q;

    for (int i = 0; i < numCourses; i++)
      if (indegree[i] == 0)
        q.push(i);

    while (q.empty() == false)
    {
      int node = q.front();
      q.pop();
      result.push_back(node);

      for (int neighbour : adjList[node])
      {
        indegree[neighbour]--;
        if (indegree[neighbour] == 0)
          q.push(neighbour);
      }
    }

    return (result.size() == numCourses) ? result : vector<int>{};
  }
};

class DFSCycleDetection
{
private:
  enum State
  {
    UNVISITED,
    PROCESSING,
    VISITED
  };
  vector<int> result;

  bool acyclic(int &node, vector<list<int>> &adjList, vector<State> &visited)
  {
    // we dont need to check this this condition would always be false
    // if (visited[node] == VISITED)
    //   return true;

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