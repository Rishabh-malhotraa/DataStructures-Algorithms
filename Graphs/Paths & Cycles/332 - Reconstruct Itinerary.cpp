#include <bits/stdc++.h>
using namespace std;

// Heirholzer's Algorithm
// Find the Eulerian Path for a given graph with a given start point [visit all edges]

// you remove the edge of the graph once you traverse a given path
// add the paths in post order

class Solution
{
private:
  string start = "JFK";

  void dfs(vector<string> &itinerary, unordered_map<string, vector<string>> &graph, string airport)
  {
    while (graph[airport].empty() == false)
    {
      string next_airport = graph[airport].back();
      if (!graph[airport].empty())
        graph[airport].pop_back();
      dfs(itinerary, graph, next_airport);
    }
    itinerary.push_back(airport);
  }

public:
  vector<string>
  findItinerary(vector<vector<string>> &tickets)
  {
    unordered_map<string, vector<string>> graph;
    for (vector<string> &ticket : tickets)
      graph[ticket[0]].push_back(ticket[1]);

    for (auto &it : graph)
      sort(it.second.begin(), it.second.end(), greater<string>());

    vector<string> itinerary;

    dfs(itinerary, graph, start);
    reverse(itinerary.begin(), itinerary.end());
    return itinerary;
  }
};