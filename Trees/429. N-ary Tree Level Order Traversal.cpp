//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  vector<Node *> children;
};

// More of a graph dfs problem than a tree problemo

class Solution
{
public:
  vector<vector<int>> levelOrder(Node *root)
  {
    if (root == NULL)
      return {};
    vector<vector<int>> result;

    queue<Node *> q({root});

    while (!q.empty())
    {
      int n = q.size();
      vector<int> list;
      for (int i = 0; i < n; i++)
      {
        Node *curr = q.front();
        q.pop();
        list.push_back(curr->val);
        for (Node *neighbour : curr->children)
          q.push(neighbour);
      }
      result.push_back(list);
    }
    return result;
  }
};