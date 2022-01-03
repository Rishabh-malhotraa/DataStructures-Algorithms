/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Graph is implemented using an edge list

/*
 * We have V-1 relaxation of edhes
 * Then there is a dp check condition d[v] = min(d[u] + w < d[v] , d[v])
 */

bool negativeCycle()
{
  int V, E;
  for (int i = 1; i <= V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        dist[v] = dist[u] + weight;
    }
  }

  // Step 3: check for negative-weight cycles.
  // The above step guarantees shortest distances
  // if graph doesn't contain negative weight cycle.
  // If we get a shorter path, then there
  // is a cycle.
  for (int i = 0; i < E; i++)
  {
    int u = graph->edge[i].src;
    int v = graph->edge[i].dest;
    int weight = graph->edge[i].weight;
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
      return true;
  }
};