/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

// COURSE SCHEDULING II using KAHNS ALGORITHM

#include <bits/stdc++.h>
using namespace std;

class Solution
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

    while (!q.empty())
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
