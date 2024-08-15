/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;


class TreeAncestor
{
private:
  vector<vector<int>> ancestors;
  int depth = 0;

public:
  TreeAncestor(int n, vector<int> &parent)
  {
    depth = ceil(log2(n)) + 1;
    ancestors.resize(n, vector<int>(depth, -1));

    for (int x = 0; x < depth; x++)
    {
      for (int node = 0; node < n; node++)
      {
        if (x == 0)
        {
          ancestors[node][0] = parent[node];
        }
        else if (ancestors[node][x - 1] != -1)
        {
          ancestors[node][x] = ancestors[ancestors[node][x - 1]][x - 1];
        }
      }
    }
  }

  int getKthAncestor(int node, int k)
  {
    for (int i = 0; i < depth; i++)
    {
      if ((1 << i) & k)
      {
        node = ancestors[node][i];
        if (node == -1)
          break;
      }
    }
    return node;
  }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */