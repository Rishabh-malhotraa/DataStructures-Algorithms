#include <bits/stdc++.h>
using namespace std;

// this took me so long to do urghhhh

// DFS to each States
class Solution
{
private:
  double eq_value = -1.0;
  unordered_map<string, list<pair<string, double>>> buildGraph(vector<vector<string>> &equations, vector<double> &values)
  {
    unordered_map<string, list<pair<string, double>>> graph;
    int n = equations.size();
    for (int i = 0; i < n; i++)
    {
      string u = equations[i][0], v = equations[i][1];
      graph[u].push_back({v, values[i]});
      graph[v].push_back({u, (1.0 / values[i])});
    }
    return graph;
  }

  void dfs(unordered_map<string, list<pair<string, double>>> &adjList, map<string, bool> &visited, string curr_node, string end_node, double &value)
  {
    if (adjList.find(curr_node) == adjList.end())
      return;

    visited[curr_node] = true;

    if (curr_node == end_node)
    {
      eq_value = value;
      return;
    }
    for (pair<string, double> neighbour : adjList[curr_node])
    {
      if (visited[neighbour.first] == false)
      {
        value = value * neighbour.second;
        dfs(adjList, visited, neighbour.first, end_node, value);
        value = value / neighbour.second;
      }
    }

    return;
  }

public:
  vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
  {
    int n = queries.size();
    vector<double> result(n, 0);

    unordered_map<string, list<pair<string, double>>> adjList = buildGraph(equations, values);

    for (int i = 0; i < n; i++)
    {
      vector<string> query = queries[i];
      map<string, bool> visited;
      string start_node = query[0];
      string end_node = query[1];
      double value = 1.0;
      eq_value = -1.0;
      dfs(adjList, visited, start_node, end_node, value);
      result[i] = this->eq_value;
    }
    return result;
  }
};