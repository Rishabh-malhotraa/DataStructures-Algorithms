/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/
#include <bits/stdc++.h>
using namespace std;

// Topological Sort

/*
1. Gathering Information
2. Contextualizing that Information
3. Beforming Topological Sort
*/

enum State
{
  UNVISITED,
  PROCESSING,
  VISITED,
};

class Solution
{
  string result;

private:
  bool acyclic(char node, unordered_map<char, State> &visited, unordered_map<char, vector<char>> &graph)
  {
    if (visited[node] == VISITED)
      return true;

    visited[node] = PROCESSING;

    for (char &neighbour : graph[node])
    {
      if (visited[neighbour] == PROCESSING)
        return false;
      if (visited[neighbour] == UNVISITED && !acyclic(neighbour, visited, graph))
        return false;
    }

    visited[node] = VISITED;
    result.push_back(node);
    return true;
  }

public:
  string alienOrder(vector<string> &words)
  {
    int n = words.size();
    unordered_map<char, vector<char>> graph;
    unordered_map<char, State> visited;

    for (string word : words)
      for (char ch : word)
      {
        graph[ch] = vector<char>();
        visited[ch] = UNVISITED;
      }

    for (int i = 0; i < n - 1; i++)
    {
      string s1 = words[i], s2 = words[i + 1];

      int len = min(s1.size(), s2.size());

      // s1 = "abcd"  && s2 = "abc"  || you should return false
      if (s1.find(s2) != string::npos && s1.size() > s2.size())
        return "";

      for (int i = 0; i < len; i++)
      {
        if (s1[i] != s2[i])
        {
          graph[s1[i]].push_back(s2[i]);
          break;
        }
      } // i don't know about contextualizing of that case????
    }
    // we need to do topological sort here

    for (pair<char, vector<char>> it : graph)
      if (visited[it.first] == UNVISITED && acyclic(it.first, visited, graph) == false)
        return "";

    reverse(result.begin(), result.end());
    return result;
  }
};
