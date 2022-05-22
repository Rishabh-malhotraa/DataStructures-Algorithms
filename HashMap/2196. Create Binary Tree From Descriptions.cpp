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
private:
  void insertIfNotPresent(unordered_map<int, TreeNode *> &cache, int key)
  {
    if (cache.find(key) == cache.end())
    {
      TreeNode *node = new TreeNode(key);
      cache[key] = node;
    }
  }

public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
  {
    unordered_map<int, TreeNode *> cache;
    unordered_set<int> nodes;
    int rootKey;

    for (vector<int> &description : descriptions)
      nodes.insert(description[1]);

    for (vector<int> &description : descriptions)
    {
      int parent = description[0], child = description[1], isLeft = description[2];
      if (nodes.find(parent) == nodes.end())
        rootKey = parent;

      insertIfNotPresent(cache, parent);
      insertIfNotPresent(cache, child);

      TreeNode *p = cache[parent];
      TreeNode *c = cache[child];

      // cout << p->val << " " << c->val << " " << p << " " << c << endl;
      (isLeft == 1) ? p->left = c : p->right = c;
    }
    return cache[rootKey];
  }
};
