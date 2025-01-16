/*



There are N cities (numbered from 1 to N, from left to right) arranged in a row and N-1 one-way roads between them: 1 → 2 → 3 → ... N-1 → N

The government plans to build M new roads. The roads will be built one by one.
The K-th road will connect the A[K]-th city with the B[K]-th city (roads are
numbered from 0 to M-1). Each road will lead from left to right, from a city
with a smaller number to a city with a larger number. No two roads will intersect.
Formally, there will be no two roads A→B and C→D where A less than C less than B less than D.

Jack lives in city number 1 and his school is located in city number N. He wants to know the distance from home to school after each new road is built.

Write a function:

vector<int> solution(vector<int>&A, vector<int>& B, int N)

that, given two arrays A, B consisting of M integers each and an integer N, returns an array D consisting of M integers. D[K] denotes the distance from home to school after building the first K roads. The distance is the minimum number of roads required to move between two cities.

Examples:

1. Given A = [2, 5, 1], B = [4, 7, 4] and N = 7, the function should return [5, 4, 3]:
    - After building the first road (2 → 4), the shortest path is: 1 → 2 → 4 → 5 → 6 → 7, length 5
    - After building the second road (5 → 7), the shortest path is: 1 → 2 → 4 → 5 → 7, length 4
    - After building the third road (1 → 4), the shortest path is: 1 → 4 → 5 → 7, length 3
2. Given A = [1, 1, 1], B = [7, 4, 6] and N = 7, the function should return [1, 1, 1]. After building the first road (1 → 7), the shortest path length is 1. Subsequent roads do not improve this result.
3. Given A = [30, 50, 40], B = [40, 60, 50] and N = 100, the function should return [90, 81, 72]. Each new road shortens the distance from home to school.

The constrains were N = 10^5 and M = 10^5


I wasn't able to come up with a solution that would meet those constraints, I think this questions was super difficult
*/


// you can use includes, for example:
#include <bits/stdc++.h>

using namespace std;

int dijkstra(const vector<vector<int>>& graph, int N) {
  vector<int> dist(N + 1, INT_MAX);
  dist[1] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({ 0, 1 });

  while (!pq.empty()) {
    int u = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    if (d > dist[u]) continue;

    for (int v : graph[u]) {
      int new_dist = dist[u] + 1;
      if (new_dist < dist[v]) {
        dist[v] = new_dist;
        pq.push({ new_dist, v });
      }
    }
  }

  return dist[N] == INT_MAX ? -1 : dist[N];
}


vector<int> solution(vector<int>& A, vector<int>& B, int N) {
  vector<int> result;
  vector<vector<int>> graph(N + 1);


  for (int i = 1; i < N; ++i) {
    graph[i].push_back(i + 1);
  }

  // processing queries
  for (int k = 0; k < (int)A.size(); ++k) {
    int a = A[k];
    int b = B[k];

    graph[a].push_back(b);

    int shortest_distance = dijkstra(graph, N);

    result.push_back(shortest_distance);
  }

  return result;
}
