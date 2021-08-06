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
  int subarraysDivByK(vector<int> &A, int K)
  {
    unordered_map<int, int> umap = {{0, 1}};
    int count = 0, curr = 0;

    for (int el : A)
    {
      curr = (curr + el) % K;
      curr = (curr + K) % K;
      count += umap[curr];
      umap[curr] += 1;
    }
    return count;
  }
};