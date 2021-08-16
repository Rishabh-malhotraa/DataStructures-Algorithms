//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numTrees(int n)
  {
    // Unique Binary Tree F(i,n) = G(LST) * G(RST)
    vector<int> G(n + 1, 0);
    G[0] = G[1] = 1;

    for (int i = 2; i < n + 1; i++)
      for (int j = 0; j < i; j++)
        G[i] += G[j] * G[i - j - 1];

    for (int g : G)
      cout << g << " ";
    return G[n];
  }
};