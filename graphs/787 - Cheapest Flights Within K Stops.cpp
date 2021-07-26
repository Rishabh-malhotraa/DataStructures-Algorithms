#include <bits/stdc++.h>
using namespace std;

// Bellman Ford Algorithm
/*
  ?:  Could be done with dijkstra to what you need to do is to ignore all the entries in the queue where steps exceed k+1

* while (!pQueue.isEmpty()) {
* 	City top = pQueue.top();

*	  if (top.city == dst) {
*		  return top.costFromSrc;
*	  }

*	  if (top.distFromSrc > K) {
*		  continue;
*/

class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    // we would require K+1 stops (V-1  relaxations in Bellman Ford for V Verticies)
    // K stops means we can have atmost K+2 vertcies
    vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));

    for (int i = 0; i <= k + 1; i++)
      dp[i][src] = 0;

    for (int i = 1; i <= k + 1; i++)
    {
      for (vector<int> &flight : flights)
      {
        int u = flight[0], v = flight[1], wt = flight[2];
        if (dp[i - 1][u] != INT_MAX)
          dp[i][v] = max(dp[i][v], dp[i - 1][u] + wt);
      }
    }
    // A -> B -> C -> D   [2 stops k = 3 flights [transfers]]
    return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
  }
};