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
  ENQUEUE,
  VISITED
};

/*
if cycle length is > 2
then the best you can do is just take that cycle

if cycle length == 2
  -             {} -  1<->2  - {}
  you can all chain lengths connected to 1 and 2 to get the length of this full chain

  - also you can connect isolated chains together

  -   {} - 1 <-> 2 - {}  && {} - 3 <-> 4 - {}

  connect the disjoint chains together :)

  Answer = max(cycle, sumOfChains)
*/

class Solution
{
private:
  unordered_map<int, list<int>> graph;
  vector<State> visited;
  int bfs(int node)
  {
    queue<int> q;
    q.push(node);
    visited[node] = VISITED;
    int distance = 0;
    while (q.empty() == false)
    {
      int n = q.size();
      for (int i = 0; i < n; i++)
      {
        int currNode = q.front();
        q.pop();

        for (int neighbour : graph[currNode])
        {
          if (visited[neighbour] == UNVISITED)
          {
            visited[neighbour] == VISITED;
            q.push(neighbour);
          }
        }
      }
      distance++;
    }
    return distance;
  }

  // the reason why this dfs can get the correct cycle length is the way the graph is structured
  int dfs(int node, int len)
  {
    if (visited[node] == VISITED)
      return 0;
    if (visited[node] == ENQUEUE)
      return len;

    visited[node] = ENQUEUE;

    int cycleLength = 0;
    for (int neighbour : graph[node])
      cycleLength = max(cycleLength, dfs(neighbour, len + 1));

    visited[node] = VISITED;
    return cycleLength;
  }

public:
  int maximumInvitations(vector<int> &favorite)
  {
    int n = favorite.size();
    visited.assign(n, UNVISITED);

    for (int i = 0; i < n; i++)
    {
      int u = i, v = favorite[i];
      graph[v].push_back(u); // reverse graph -> this would help for bfs and cycles are uneffected
    }

    int sumOfChains = 0;

    for (int i = 0; i < n; i++)
    {
      int u = i, v = favorite[i];
      if (favorite[favorite[i]] == i)
      {
        // u <-> v

        if (visited[u] == UNVISITED)
        {
          visited[u] = visited[v] = VISITED;
          int chain1 = bfs(u);
          int chain2 = bfs(v);
          sumOfChains += chain1 + chain2; // two independant chains can be clubbed together
        }
      }
    }
    // dfs is used in order to find cycle
    int cycle = 0;
    for (int i = 0; i < favorite.size(); i++)
      cycle = max(cycle, dfs(i, 0));

    return max(sumOfChains, cycle);
  }
};