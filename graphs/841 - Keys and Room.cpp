#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int node)
  {
    if (visited[node])
      return;

    visited[node] = true;

    for (int neighbour : rooms[node])
      dfs(rooms, visited, neighbour);

    return;
  }

  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    int n = rooms.size();
    vector<bool> visited(n, false);
    dfs(rooms, visited, 0);

    for (bool isVisited : visited)
      if (isVisited == false)
        return false;

    return true;
  }
};
