#include <bits/stdc++.h>
using namespace std;
/*

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.


Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

     0
    / \
  0.5  0.2
 /      \
1  -0.5-  2

.5*.5 -> .25

Method 1:  do a dfs search with keeping track of probability

we keep traversing for end point -> a --- c ---- e ----> b  : then you keep track of the probability

result = max(resulyt, currResult)

1  -> 2
1 <-> 2

there could be many paths going from a to b


Method 2: dijsktra algorithm


0 -> 1


you have a priorty queue -> you are at zero


you push all the element that are neighbour of node0 into the PQ

after pushing you mark o as visited

0  -> 1 ->  2
      0.5    0.2



after this you pop of the best possible result

1 -> 2       2
     0.25    0.2

you pop off 1 and you look at its beighbour


O(V + E)

O(V + ElogE) --> early termination


 0 -> 1  -> 2
|
| -> -------


vector
[0] ->  {1, 0.5}    {2, 0.2}

[1] ->  {}
*/

/*

Time complexity -> O(V + Elog(V))

Space Complexity -> O(E+V)


*/

class Solution
{

private:
  vector<list<pair<int, double>>> buildGraph(int n, vector<vector<int>> edges, vector<double> succProb)
  {
    vector<list<pair<int, double>>> graph(n);
    int idx = 0;
    for (vector<int> edge : edges)
    {
      int u = edge[0], v = edge[1];
      double wt = succProb[idx++];

      graph[u].push_back({v, wt});
      graph[v].push_back({u, wt});
    }
    return graph;
  }

public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
  {
    vector<list<pair<int, double>>> graph = buildGraph(n, edges, succProb);

    vector<bool> visited(n, false);

    priority_queue<pair<double, int>> pq;

    pq.push({1, start});

    while (pq.empty() == false)
    {
      auto &[probability, currNode] = pq.top();
      pq.pop();

      visited[currNode] = true;

      if (currNode == end)
        return probability;

      for (auto &[neighbourNode, neighbourProbability] : graph[currNode])
      {
        double currProbability = probability * neighbourProbability;
        if (visited[neighbourNode] == false)
          pq.push({currProbability, neighbourNode});
      }
    }

    return 0.0;
  }
};