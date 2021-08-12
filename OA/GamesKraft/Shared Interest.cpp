//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int node;
  int interest;
};

map<pair<int, int>, int> f;

void dfs(int node, int interest, int parent, unordered_map<int, list<Node>> &graph, vector<bool> &visited)
{
  if (visited[node] == true)
    return;

  int min = std::min(parent, node);
  int max = std::max(parent, node);
  pair<int, int> p = {min, max};
  f[p] += 1;
  visited[node] = true;

  for (Node el : graph[node])
    if (el.interest == interest && visited[el.node] == false)
      dfs(el.node, interest, parent, graph, visited);

  visited[node] = false;
}

int maxShared(int n, vector<int> A, vector<int> B, vector<int> W)
{
  f.clear();
  unordered_map<int, list<Node>> graph;

  for (int i = 0; i < A.size(); i++)
  {
    int u = A[i], v = B[i], interest = W[i];
    graph[u].push_back({v, interest});
    graph[v].push_back({u, interest});
  }

  for (int i = 1; i <= n; i++)
  {
    vector<bool> visited(n, false);
    for (Node el : graph[i])
    {
      visited[i] = true;
      dfs(el.node, el.interest, i, graph, visited);
    }
  }
  int max_value = 0, max_connections = 0;
  for (auto el : f)
  {
    int value = el.first.first * el.first.second;
    int connections = el.second;
    cout << el.first.first << " " << el.first.second << "  " << connections << " " << value << " " << endl;

    if (connections == max_connections)
      max_value = max(max_value, value);
    else if (connections > max_connections)
    {
      max_connections = connections;
      max_value = value;
    }
  }
  cout << endl;
  return max_value;
}

/*
1
5 7
1 2 1
1 2 2
2 3 1
2 3 3
2 4 3
4 5 1
4 5 2

Ans = 20


1
4 5
1 2 1
1 2 2
2 3 1
2 3 3
2 4 3

Ans = 6

i j  n val
1 2  4 2 
1 3  2 3 
2 3  4 6 
2 4  2 8 
3 4  2 12 
4 5  4 20 
20

1 2  4 2 
1 3  2 3 
2 3  4 6 
2 4  2 8 
3 4  2 12 
6



*/

/*
  - Most time spent & I did not follow my approach thats why I messed up D:
  - You just needed to dfs on every cell wth previous cell interest wt interest to see a connection
  - this is why does the set solution not work  https://ibb.co/C2FvQH2
  - TC : 5/14 Passed!

int maxShared(int friends_nodes, vector<int> A, vector<int> B,
              vector<int> W)
{
  map<pair<int, int>, int> f;

  unordered_map<int, set<int>> cache;

  int n = A.size();
  for (int i = 0; i < n; i++)
  {
    int wt = W[i];
    cache[wt].insert(A[i]);
    cache[wt].insert(B[i]);
  }

  pair<int, int> max_pair;
  int max_value = 0;
  for (auto el : cache)
  {
    set<int> s = el.second;
    vector<int> arr(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        pair<int, int> p = {arr[i], arr[j]};
        f[p] += 1;
        if (f[p] > max_value)
        {
          max_value = f[p];
          max_pair = p;
        }
      }
    }
    return max_pair.first * max_pair.second;
  }
}

*/