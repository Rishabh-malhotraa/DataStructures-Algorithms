/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Good BFS | DFS Problem

class Solution
{
public:
  int minReorder(int n, vector<vector<int>> &connections)
  {
    vector<list<int>> adj(n), back(n);
    vector<bool> visited(n, false);
    for (vector<int> &connection : connections)
    {
      int u = connection[0], v = connection[1];
      adj[u].push_back(v);
      back[v].push_back(u);
    }
    int result = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
      int curr = q.front();
      visited[curr] = true;
      q.pop();

      for (int neighbour : adj[curr])
        if (visited[neighbour] == false)
        {
          result++;
          q.push(neighbour);
        }

      for (int neighbour : back[curr])
        if (visited[neighbour] == false)
          q.push(neighbour);
    }

    return result;
  }
};