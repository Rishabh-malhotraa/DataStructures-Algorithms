/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  // directed acyclic graph to undirected acyclic graph
  void buildGraph(TreeNode *root, unordered_map<int, vector<int>> &graph)
  {

    if (root->left != NULL)
    {
      graph[root->val].push_back(root->left->val);
      graph[root->left->val].push_back(root->val);
      buildGraph(root->left, graph);
    }
    if (root->right != NULL)
    {
      graph[root->val].push_back(root->right->val);
      graph[root->right->val].push_back(root->val);
      buildGraph(root->right, graph);
    }
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
  {

    if (K == 0)
      return {target->val};

    // initialisation

    unordered_map<int, vector<int>> graph; // graph
    // since all node val are unique
    unordered_map<int, bool> visited;
    vector<int> nodes;
    queue<int> q;
    int level = 0;

    // build the graph
    buildGraph(root, graph);

    // push the target to start bfs with
    q.push(target->val);

    // bfs
    while (!q.empty())
    {
      int len = q.size();
      for (int i = 0; i < len; i++)
      {

        int curr = q.front();
        q.pop();
        visited[curr] = true;

        for (int x : graph[curr])
          if (!visited[x])
            q.push(x);
      }
      level++;
      // we reached the Kth layer, push the layer in nodes vector and break bfs
      if (level == K)
      {
        while (!q.empty())
          nodes.push_back(q.front()), q.pop();
        break;
      }
    }

    return nodes;
  }
};