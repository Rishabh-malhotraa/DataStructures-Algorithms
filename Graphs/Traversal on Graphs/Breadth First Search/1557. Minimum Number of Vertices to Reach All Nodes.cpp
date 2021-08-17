// 1557. Minimum Number of Vertices to Reach All Nodes
//? Graphs | Mother Vertex | OutDegree

#include <bits/stdc++.h>
using namespace std;

/*
 * A node that does not have any incoming edge can only be reached by itself.
 * Any other node with incoming edges can be reached from some other node.
 * We only have to count the number of nodes with zero incoming edges.
*/

class Solution
{
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
  {
    vector<int> outdegree(n, 0), result;

    for (vector<int> &edge : edges)
      outdegree[edge[1]]++;

    for (int i = 0; i < n; i++)
      if (outdegree[i] == 0)
        result.push_back(i);

    return result;
  }
};
