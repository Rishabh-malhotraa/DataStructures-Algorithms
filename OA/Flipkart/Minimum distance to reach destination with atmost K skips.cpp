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
A state consists of N cities numbered from 0 to N-1. All the road in the state are bidirectional.
Each city is connected to another city by one direct road only. A magician travels  to these cities to perform shows.
He knows a magic spell that can completely eliminate the distance between any two directly connected cities.
But he must be very carefuil because the magic spell can be performed only K number of times 

Write an algorithm to find the length of the shortest route between two given cities after performing magic spell K number of times.
Output -1 if no path exist.
*/

// NOT WORKING >:(

#include <bits/stdc++.h>
using namespace std;

int n, src, dst, k;

vector<list<pair<int, int>>> buildGraph(vector<vector<int>> edgeList)
{
  vector<list<pair<int, int>>> adjList(n);
  for (vector<int> edges : edgeList)
  {
    int u = edges[0];
    int v = edges[1];
    int wt = edges[2];
    adjList[u].push_back({v, wt});
    adjList[v].push_back({u, wt});
  }
  return adjList;
}

int findShortestDistance(vector<vector<int>> &edgeList)
{
  int result = INT_MAX;
  vector<int> visited(n, -1);
  auto adjList = buildGraph(edgeList);

  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
  q.push({0, src, src, k});

  while (q.empty() == false)
  {
    vector<int> curr = q.top();
    q.pop();
    int path = curr[0], node = curr[1], prev = curr[2], lives = curr[3];

    cout << node << " " << path << " " << lives << endl;

    if (node == dst)
      result = min(path, result);

    // if (visited[node] != -1 && visited[node] > lives)
    //   continue;

    for (pair<int, int> el : adjList[node])
    {
      if (el.first == prev)
        continue;
      visited[lives] = max(lives, visited[lives]);
      q.push({path + el.second, el.first, node, lives});
      if (lives != 0)
        q.push({path, el.first, node, lives - 1});
    }
  }

  return (result == INT_MAX) ? -1 : result;
}

void solve()
{
  cin >> n;
  cin >> src >> dst;
  cin >> k;

  int z, q;
  cin >> z >> q;

  vector<vector<int>> edgeList(z, vector<int>(3, 0));
  for (int i = 0; i < z; i++)
    cin >> edgeList[i][0] >> edgeList[i][1] >> edgeList[i][2];

  cout << findShortestDistance(edgeList) << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}