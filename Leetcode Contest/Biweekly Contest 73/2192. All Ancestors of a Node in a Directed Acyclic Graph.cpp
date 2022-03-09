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
  vector<vector<int>> ancestors;

  vector<int> bfs(int i, vector<list<int>> &adjList)
  {
    int n = adjList.size();
    queue<int> q;
    q.push(i);
    vector<bool> visited(n, false);

    set<int> res;
    while (!q.empty())
    {
      auto node = q.front();
      q.pop();

      for (int &neighbour : adjList[node])
      {
        if (visited[neighbour] == false)
        {
          res.insert(neighbour);
          if (ancestors[neighbour].size() != 0)
          {
            res.insert(ancestors[neighbour].begin(), ancestors[neighbour].end());
          }
          else
          {
            visited[neighbour] = true;
            q.push(neighbour);
          }
        }
      }
    }

    // for(int el : res)
    //   cout << el << " ";
    // cout << endl;

    return vector<int>(res.begin(), res.end());
  }

public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
  {
    vector<list<int>> adjList(n);
    ancestors.assign(n, {});
    for (vector<int> &course : edges)
    {
      int u = course[0], v = course[1];
      adjList[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
      ancestors[i] = bfs(i, adjList);
    }
    return ancestors;
  }
};

// class Solution
// {
// public:
//   vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
//   {
//     vector<list<int>> adjList(n);
//     vector<pair<int, int>> topoSort;
//     vector<vector<int>> result(n);
//     for (vector<int> &course : edges)
//     {
//       int u = course[0], v = course[1];
//       adjList[u].push_back(v);
//     }

//     vector<int> indegree(n, 0);

//     for (auto list : adjList)
//       for (int node : list)
//         indegree[node]++;

//     queue<pair<int, int>> q;

//     for (int i = 0; i < n; i++)
//       if (indegree[i] == 0)
//         q.push({i, 0});

//     while (q.empty())
//     {
//       auto [node, level] = q.front();
//       q.pop();
//       topoSort.push_back({node, level});

//       for (int neighbour : adjList[node])
//       {
//         indegree[neighbour]--;
//         if (indegree[neighbour] == 0)
//           q.push({neighbour, level + 1});
//       }
//     }

//     for (int i = 0; i < n; i++)
//     {
//       vector<int> ancestors;
//       for (int j = 0; j < i; j++)
//         if (topoSort[j].second < topoSort[i].second)
//           ancestors.push_back(topoSort[j].first);
//       result.push_back(ancestors);
//     }
//     return result;
//   }
// };
