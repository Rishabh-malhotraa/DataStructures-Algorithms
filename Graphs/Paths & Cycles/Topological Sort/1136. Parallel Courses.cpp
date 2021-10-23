/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  vector<list<int>> buildGraph(vector<vector<int>> edgeList, int n)
  {
    vector<list<int>> adjList(n);
    for (vector<int> edges : edgeList)
    {
      int u = edges[0];
      int v = edges[1];
      adjList[u].push_back(v);
    }
    return adjList;
  }

public:
  int minimumSemesters(int n, vector<vector<int>> &relations)
  {
  }
};